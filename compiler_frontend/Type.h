#ifndef TYPE_H
#define TYPE_H

#include "Word.h"

class Type : public Word{
public:
    
    Type(std::string s, int tag, int w);
    
    static bool numeric(Type *p);
    static Type* max(Type *p1, Type *p2);
    
    int width = 0;
    
    static Type *const Int;
    static Type *const Float;
    static Type *const Bool;
    static Type *const Char;
    
private:
    static Type Intv;
    static Type Floatv;
    static Type Charv;
    static Type Boolv;
};

#endif
