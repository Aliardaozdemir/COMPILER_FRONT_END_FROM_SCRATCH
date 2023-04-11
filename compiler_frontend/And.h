#ifndef AND_H
#define AND_H

#include "Logical.h"

class And : public Logical{
public:
    And(Token *tok, Expr *x1, Expr *x2);
    void jumping(int t, int f);
};

#endif
