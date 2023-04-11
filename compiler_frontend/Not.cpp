#include "Not.h"

Not::Not(Token *tok, Expr *x2)
: Logical(tok, x2, x2)
{}

void Not::jumping(int t, int f){
    expr2->jumping(f, t);
}

std::string Not::toString() const{
    std::string str( op->toString() + " " + expr2->toString() );
    return str;
}
