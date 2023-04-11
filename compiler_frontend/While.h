#ifndef WHILE_H
#define WHILE_H

#include "Stmt.h"

class While : public Stmt{
public:
    While();
    void init(Expr *x, Stmt *s);
    void gen(int b, int a);
    
    Expr *expr;
    Stmt *stmt;
};

#endif
