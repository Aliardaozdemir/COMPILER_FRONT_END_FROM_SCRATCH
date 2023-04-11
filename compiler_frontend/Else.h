#ifndef ELSE_H
#define ELSE_H

#include "Stmt.h"

class Else : public Stmt{
public:
    Else(Expr *x, Stmt *s1, Stmt *s2);
    void gen(int b, int a);
    
    Expr *expr;
    Stmt *stmt1;
    Stmt *stmt2;
};

#endif
