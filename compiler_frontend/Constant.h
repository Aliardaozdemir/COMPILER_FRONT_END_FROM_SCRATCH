#ifndef CONSTANT_H
#define CONSTANT_H

#include "Expr.h"
#include "Num.h"

class Constant : public Expr{
public:
    Constant(Token *tok, Type *p);
    Constant(int i);
    
    void jumping(int t, int f);
    
    ~Constant();

    
    static Constant *const True;
    static Constant *const False;
    
private:
    Num *tempPtr;
    
    static Constant Truev;
    static Constant Falsev;
};

#endif
