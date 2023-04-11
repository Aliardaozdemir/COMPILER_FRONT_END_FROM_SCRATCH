#include "Parser.h"

Parser::Parser(Lexer *l)
: lex(l)
{
    move();
}

void Parser::move(){
    look = lex->scan();
}

void Parser::error(std::string s){
    if(true)
        throw std::invalid_argument("near line " + std::to_string(Lexer::line) + ": " + s);
}

void Parser::match(int t){
    if( look->tag == t )
        move();
    else
        error("syntax error");
}

void Parser::program(){
    Stmt *s = block();
    int begin = s->newlabel();
    int after = s->newlabel();
    s->emitlabel(begin);
    s->gen(begin, after);
    s->emitlabel(after);
}

Stmt* Parser::block(){
    match('{');
    Env* savedEnv = top;
    top = new Env(top);
    decls();
    Stmt *s = stmts();
    match('}');
    top = savedEnv;
    return s;
}

void Parser::decls(){
    while( look->tag == Tag::BASIC ){
        Type *p = type();
        Token *tok = look;
        match(Tag::ID);
        match(';');
        Id *id = new Id(dynamic_cast<Word*>(tok), p, used);
        top->put(tok, id);
        used = used + p->width;
    }
}

Type* Parser::type(){
    Type* p = dynamic_cast<Type*>(look);
    
    match(Tag::BASIC);
    if( look->tag != '[' )
        return p;
    else
        return dims(p);
}

Type* Parser::dims(Type *p){
    match('[');
    Token *tok = look;
    match(Tag::NUM);
    match(']');
    p = dims(p);
    Array *temp1 = new Array(dynamic_cast<Num*>(tok)->value, p);
    return temp1;
}

Stmt* Parser::stmts(){
    if( look->tag == '}' )
        return Stmt::Null;
    else{
        Seq *temp2 = new Seq(stmt(), stmts());
        return temp2;
    }
}

Stmt* Parser::stmt(){
    Expr *x;
    Stmt *s;
    Stmt *s1;
    Stmt *s2;
    
    Stmt *savedStmt;
    
    switch( look->tag ){
        case ';':{
            move();
            return Stmt::Null;}
        case Tag::IF:{
            match(Tag::IF);
            match('(');
            x = bool_();
            match(')');
            s1 = stmt();
            if( look->tag != Tag::ELSE ){
                If *temp3 = new If(x, s1);
                return temp3;
            }
            match(Tag::ELSE);
            s2 = stmt();
            Else *temp4 = new Else(x, s1, s2);
            return temp4;}
        case Tag::WHILE:{
            While *whilenode = new While();
            savedStmt = Stmt::Enclosing;
            Stmt::Enclosing = whilenode;
            match(Tag::WHILE);
            match('(');
            x = bool_();
            match(')');
            s1 = stmt();
            whilenode->init(x, s1);
            Stmt::Enclosing = savedStmt;
            return whilenode;}
        case Tag::DO:{
            Do *donode = new Do();
            savedStmt = Stmt::Enclosing;
            Stmt::Enclosing = donode;
            match(Tag::DO);
            s1 = stmt();
            match(Tag::WHILE);
            match('(');
            x = bool_();
            match(')');
            match(';');
            donode->init(s1, x);
            Stmt::Enclosing = savedStmt;
            return donode;}
        case Tag::BREAK:{
            match(Tag::BREAK);
            match(';');
            Break *temp5 = new Break();
            return temp5;}
        case '{':{
            return block();}
        default:{
            return assign();}
    }//end
}

Stmt* Parser::assign(){
    Stmt *stmt;
    Token *t = look;
    match(Tag::ID);
    Id *id = top->get(t);
    if( id == nullptr )
        error(t->toString() + " undeclared");
    if( look->tag == '=' ){
        move();
        stmt = new Set(id, bool_());
    }
    else{
        Access *x = offset(id);
        match('=');
        stmt = new SetElem(x, bool_());
    }
    match(';');
    return stmt;
}

Expr* Parser::bool_(){
    Expr *x = join();
    while( look->tag == Tag::OR ){
        Token *tok = look;
        move();
        x = new Or(tok, x, join());
    }
    return x;
}

Expr* Parser::join(){
    Expr *x = equality();
    while( look->tag == Tag::AND ){
        Token *tok = look;
        move();
        x = new And(tok, x, equality());
    }
    return x;
}

Expr* Parser::equality(){
    Expr *x = rel();
    while( look->tag == Tag::EQ || look->tag == Tag::NE ){
        Token *tok = look;
        move();
        x = new Rel(tok, x, rel());
    }
    return x;
}

Expr* Parser::rel(){
    Expr *x = expr();
    
    switch( look->tag ){
        case '<':
        case Tag::LE:
        case Tag::GE:
        case '>':{
            Token *tok = look;
            move();
            Rel *temp6 = new Rel(tok, x, expr());
            return temp6;}
        default:{
            return x;}
    }
}

Expr* Parser::expr(){
    Expr *x = term();
    while( look->tag == '+' || look->tag == '-' ){
        Token *tok = look;
        move();
        x = new Arith(tok, x, term());
    }
    return x;
}

Expr* Parser::term(){
    Expr *x = unary();
    while(look->tag == '*' || look->tag == '/' ){
        Token *tok = look;
        move();
        x = new Arith(tok, x, unary());
    }
    return x;
}

Expr* Parser::unary(){
    if( look->tag == '-' ){
        move();
        Unary *temp7 = new Unary(Word::minus, unary());
        return temp7;
    }
    else if( look->tag == '!' ){
        Token *tok = look;
        move();
        Not *temp8 = new Not(tok, unary());
        return temp8;
    }
    else{
        return factor();
    }
    
}


Expr* Parser::factor(){
    Expr *x = nullptr;
    switch(look->tag){
        case '(':{
            move();
            x = bool_();
            match(')');
            return x;}
        case Tag::NUM:{
            x = new Constant(look, Type::Int);
            move();
            return x;}
        case Tag::REAL:{
            x = new Constant(look, Type::Float);
            move();
            return x;}
        case Tag::TRUE:{
            x = Constant::True;
            move();
            return x;}
        case Tag::FALSE:{
            x = Constant::False;
            move();
            return x;}
        case Tag::ID:{
            std::string s = look->toString();
            Id *id = top->get(look);
            if(id == nullptr)
                error(look->toString() + " undeclared");
            move();
            if(look->tag != '[')
                return id;
            else
                return offset(id);}
        default:{
            error("syntax error");
            return x;
        }
            
    }//end
    
}

Access* Parser::offset(Id *a){
    Expr *i;
    Expr *w;
    Expr *t1;
    Expr *t2;
    Expr *loc;
    
    Type *type = a->type;
    
    match('[');
    i = bool_();
    match(']');
    type = dynamic_cast<Array*>(type)->of;
    w = new Constant(type->width);
    t1 = new Arith(new Token('*'), i, w);
    loc = t1;
    
    while( look->tag == '[' ){
        match('[');
        i = bool_();
        match(']');
        type = dynamic_cast<Array*>(type)->of;
        w = new Constant(type->width);
        t1 = new Arith(new Token('*'), i, w);
        t2 = new Arith(new Token('+'), loc, t1);
        loc = t2;
    }
    return new Access(a,loc,type);
}



