#ifndef EXPR_H
#define EXPR_H

#include "Node.h"
#include "Token.h"
#include "Type.h"

class Expr : public Node{
public:
    Expr(Token *tok, Type *p);
    Expr* gen();
    Expr* reduce();
    void jumping(int t, int f);
    void emitjumps(std::string test, int t, int f);
    std::string toString() const;
    
    Token *op;
    Type *type;
};

#endif
