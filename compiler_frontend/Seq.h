#ifndef SEQ_H
#define SEQ_H

#include "Stmt.h"

class Seq : public Stmt{
public:
    Seq(Stmt *s1, Stmt *s2);
    void gen(int b, int a);
    
    
    Stmt *stmt1;
    Stmt *stmt2;
};

#endif
