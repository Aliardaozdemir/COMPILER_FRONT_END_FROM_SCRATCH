#ifndef WORD_H
#define WORD_H

#include "Token.h"

class Word : public Token{
public:
    Word(std::string s, int tag);
    std::string toString() const;
    
    std::string lexeme = "";
    
    static Word *const and_;
    static Word *const or_;
    static Word *const eq;
    static Word *const ne;
    static Word *const le;
    static Word *const ge;
    static Word *const minus;
    static Word *const True;
    static Word *const False;
    static Word *const temp;
    
private:
    static Word and_v;
    static Word or_v;
    static Word eqv;
    static Word nev;
    static Word lev;
    static Word gev;
    static Word minusv;
    static Word Truev;
    static Word Falsev;
    static Word tempv;

};

#endif
