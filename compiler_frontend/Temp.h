#ifndef TEMP_H
#define TEMP_H

#include "Expr.h"
#include "Type.h"
#include "Word.h"

class Temp : public Expr{
public:
    Temp(Type *p);
    std::string toString() const;
    
    static int count;
    int number = 0;
};

#endif
