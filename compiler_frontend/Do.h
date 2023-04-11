#ifndef DO_H
#define DO_H

#include "Stmt.h"

class Do : public Stmt{
public:
    Do();
    void init(Stmt *s, Expr *x);
    void gen(int b, int a);
    
    Expr *expr;
    Stmt *stmt;
};

#endif
