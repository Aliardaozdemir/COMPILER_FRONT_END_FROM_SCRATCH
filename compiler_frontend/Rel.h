#ifndef REL_H
#define REL_H

#include "Logical.h"
#include "INSTANCE.h"
#include "Array.h"

class Rel : public Logical{
public:
    Rel(Token *tok, Expr *x1, Expr *x2);
    Type* check(Type *p1, Type *p2);
    void jumping(int t, int f);
    
};

#endif
