#ifndef UNARY_H
#define UNARY_H

#include "Op.h"

class Unary : public Op{
public:
    Unary(Token *tok, Expr *x);
    Expr* gen();
    std::string toString() const;
    ~Unary();
    
    Expr *expr;
private:
    Unary *tempPtr;
};

#endif
