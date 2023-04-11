#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stdexcept>

#include "Lexer.h"
#include "Token.h"
#include "Env.h"
#include "Stmt.h"
#include "Type.h"
#include "Access.h"
#include "Id.h"
#include "Array.h"
#include "Num.h"
#include "Seq.h"
#include "If.h"
#include "Else.h"
#include "While.h"
#include "Do.h"
#include "Break.h"
#include "Set.h"
#include "SetElem.h"
#include "Or.h"
#include "And.h"
#include "Rel.h"
#include "Arith.h"
#include "Unary.h"
#include "Constant.h"
#include "Not.h"

class Parser{
public:
    explicit Parser(Lexer *l);
    void move();
    void error(std::string s);
    void match(int t);
    void program();
    Stmt* block();
    void decls();
    Type* type();
    Type* dims(Type *p);
    Stmt* stmts();
    Stmt* stmt();
    Stmt* assign();
    Expr* bool_();
    Expr* join();
    Expr* equality();
    Expr* rel();
    Expr* expr();
    Expr* term();
    Expr* unary();
    Expr* factor();
    Access* offset(Id *a);
    
    int used = 0;
    Env *top;
private:
    Lexer *lex;
    Token *look;
};

#endif
