#ifndef OR_H
#define OR_H

#include "Logical.h"

class Or : public Logical{
public:
    Or(Token *tok, Expr *x1, Expr *x2);
    void jumping(int t, int f);
};
#endif
