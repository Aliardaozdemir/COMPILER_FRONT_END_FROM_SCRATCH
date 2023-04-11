#ifndef STMT_H
#define STMT_H

#include "Expr.h"

class Stmt : public Node{
public:
    Stmt();
    void gen(int b, int a);
    
    
    int after = 0;
    static Stmt *Null;
    static Stmt *Enclosing;
};

#endif
