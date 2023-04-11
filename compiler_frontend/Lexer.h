#ifndef LEXER_H
#define LEXER_H

#include "HashTable.h"
#include "Word.h"
#include "Type.h"
#include "Token.h"
#include "Num.h"
#include "Real.h"
#include <iostream>

class Lexer{
public:
    
    Lexer();
    void reserve(Word *w);
    void readch();
    bool readch(char c);
    Token* scan();
    ~Lexer();
    
    HashTable words;
    char peek = ' ';
    static int line;
    
private:
    Token *tempPtr[15];
};

#endif
