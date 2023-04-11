#ifndef BREAK_H
#define BREAK_H

#include "Stmt.h"

class Break : public Stmt{
public:
    Break();
    void gen(int b, int a);
    
    Stmt *stmt;
};

#endif
