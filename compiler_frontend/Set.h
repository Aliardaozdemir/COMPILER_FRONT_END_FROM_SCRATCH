#ifndef SET_H
#define SET_H

#include "Id.h"
#include "Stmt.h"

class Set : public Stmt{
public:

    Set(Id *i, Expr *x);
    Type* check(Type *p1, Type *p2);
    void gen(int b, int a);
    
    
    Id *id;
    Expr *expr;
};

#endif
