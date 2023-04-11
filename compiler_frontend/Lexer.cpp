#include "Lexer.h"

int Lexer::line = 1;

void Lexer::reserve(Word *w){
    words.put(w->lexeme, w);
}

Lexer::Lexer(){
    Word *t1 = new Word("if", Tag::IF);
    tempPtr[0] = t1;
    reserve(t1);
    
    Word *t2 = new Word("else", Tag::ELSE);
    tempPtr[1] = t2;
    reserve(t2);
    
    Word *t3 = new Word("while", Tag::WHILE);
    tempPtr[2] = t3;
    reserve(t3);
    
    Word *t4 = new Word("do", Tag::DO);
    tempPtr[3] = t4;
    reserve(t4);
    
    Word *t5 = new Word("break", Tag::BREAK);
    tempPtr[4] = t5;
    reserve(t5);
    
    reserve(Word::True); reserve(Word::False); reserve(Type::Int);
    reserve(Type::Bool); reserve(Type::Float); reserve(Type::Char);
    
}



void Lexer::readch(){
    char c = std::cin.get();
    if( c == EOF )
        return;
    peek = c;
}

bool Lexer::readch(char c){
    readch();
    if(peek != c)
        return false;
    peek = ' ';
    return true;
}

Token* Lexer::scan(){
    
    for(;;readch()){
        if(peek == ' ' || peek == '\t')
            continue;
        else if(peek == '\n')
            line += 1;
        else
            break;
    }
    
    switch(peek){
        case '&':
            if( readch('&') ) return Word::and_;
            else{
                Token *t6 = new Token('&');
                tempPtr[5] = t6;
                return t6;
            }
        case '|':
            if( readch('|') ) return Word::or_;
            else{
                Token *t7 = new Token('|');
                tempPtr[6] = t7;
                return t7;
            }
        case '=':
            if( readch('=') ) return Word::eq;
            else{
                Token *t8 = new Token('=');
                tempPtr[7] = t8;
                return t8;
            }
        case '!':
            if( readch('=') ) return Word::ne;
            else{
                Token *t9 = new Token('!');
                tempPtr[8] = t9;
                return t9;
            }
        case '<':
            if( readch('=') ) return Word::le;
            else{
                Token *t10 = new Token('<');
                tempPtr[9] = t10;
                return t10;
            }
        case '>':
            if( readch('=') ) return Word::ge;
            else{
                Token *t11 = new Token('>');
                tempPtr[10] = t11;
                return t11;
            }
    }//end of switch
    
    if( std::isdigit(peek) ){
        int v = 0;
        do{
            v = v*10 + (peek -'0');
            readch();
        }while(std::isdigit(peek));
        
        if( peek != '.' ){
            Num *t12 = new Num(v);
            tempPtr[11] = t12;
            return t12;
        }
        
        float x = v;
        float d = 10;
        
        for(;;){
            readch();
            if(!std::isdigit(peek))
                break;
            x = x + (peek - '0') / d;
            d = d*10;
        }
        Real *t13 = new Real(x);
        tempPtr[12] = t13;
        return t13;
    }
    
    if(std::isalpha(peek)){
        std::string s("");
        
        do{
            s += peek;
            readch();
        }while(std::isdigit(peek) || std::isalpha(peek));
        
        Word *w = words.get(s);
        if(w != nullptr)
            return w;
        
        Word *t14 = new Word(s, Tag::ID);
        tempPtr[13] = t14;
        words.put(s, t14);
        return t14;
    }
    
    Token *t15 = new Token(peek);
    tempPtr[14] = t15;
    peek = ' ';
    return t15;
}


Lexer::~Lexer(){
    for(int i= 0; i < 15; i++){
        delete tempPtr[i];
        tempPtr[i] = nullptr;
    }
}







