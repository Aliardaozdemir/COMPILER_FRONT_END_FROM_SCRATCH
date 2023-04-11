#ifndef NOT_H
#define NOT_H

#include "Logical.h"

class Not : public Logical{
public:
    Not(Token *tok, Expr *x2);
    void jumping(int t, int f);
    std::string toString() const;
};

#endif
