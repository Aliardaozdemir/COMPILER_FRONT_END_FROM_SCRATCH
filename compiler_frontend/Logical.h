#ifndef LOGICAL_H
#define LOGICAL_H

#include "Expr.h"
#include "Temp.h"

class Logical : public Expr{
public:
    Logical(Token *tok, Expr *x1, Expr *x2);
    Type* check(Type *p1, Type *p2);
    Expr* gen();
    std::string toString() const;
    ~Logical();
    
    Expr *expr1;
    Expr *expr2;
private:
    Temp *tempPtr;
};

#endif
