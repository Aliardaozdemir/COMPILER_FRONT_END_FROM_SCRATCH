#ifndef OP_H
#define OP_H

#include "Expr.h"
#include "Temp.h"

class Op : public Expr{
public:
    Op(Token *tok, Type *p);
    Expr* reduce();
    ~Op();
private:
    Expr *tempPtr;
};

#endif
