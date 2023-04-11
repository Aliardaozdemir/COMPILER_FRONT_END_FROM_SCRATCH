#ifndef SETELEM_H
#define SETELEM_H

#include "Id.h"
#include "Access.h"
#include "INSTANCE.h"
#include "Array.h"
#include "Stmt.h"

class SetElem : public Stmt{
public:
    SetElem(Access *x, Expr *y);
    Type* check(Type *p1, Type *p2);
    void gen(int b, int a);
    
    Expr *index;
    Expr *expr;
    Id *array;
};

#endif
