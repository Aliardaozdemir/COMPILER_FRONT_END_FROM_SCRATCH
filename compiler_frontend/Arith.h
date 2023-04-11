#ifndef ARITH_H
#define ARITH_H

#include "Op.h"

class Arith : public Op{
public:
    Arith(Token *tok, Expr *x1, Expr *x2);
    Expr* gen();
    std::string toString() const;
    ~Arith();
    
    Expr *expr1;
    Expr *expr2;
    
private:
    Arith *tempPtr;
};

#endif
