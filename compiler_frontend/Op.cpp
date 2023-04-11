#include "Op.h"

Op::Op(Token *tok, Type *p)
: Expr(tok, p), tempPtr(nullptr)
{
    //
}

Expr* Op::reduce(){
    Expr *x = gen();
    
    tempPtr = new Temp(type);
    
    emit_(tempPtr->toString() + " = " + x->toString());
    
    return tempPtr;
}

Op::~Op(){
    delete tempPtr;
    tempPtr = nullptr;
}
