#ifndef ID_H
#define ID_H

#include "Expr.h"
#include "Word.h"
#include "Type.h"

class Id : public Expr{
public:
    Id(Word *id, Type *p, int b);
    int offset;
};

#endif
