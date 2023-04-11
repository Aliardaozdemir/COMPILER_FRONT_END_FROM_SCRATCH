#ifndef IF_H
#define IF_H


#include "Stmt.h"


class If : public Stmt{
public:
    If(Expr *x, Stmt *s);
    void gen(int b, int a);
    
    Expr *expr;
    Stmt *stmt;
};

#endif
