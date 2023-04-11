#include "Arith.h"

Arith::Arith(Token *tok, Expr *x1, Expr *x2)
: Op(tok, nullptr), expr1(x1), expr2(x2), tempPtr(nullptr)
{
    Type *ptr = Type::max(expr1->type, expr2->type);
    if(ptr == nullptr)
        error("type error");
}

Expr* Arith::gen(){
    tempPtr = new Arith(op, expr1->reduce(), expr2->reduce());
    return tempPtr;
}

std::string Arith::toString() const{
    std::string str( expr1->toString() + " "+ op->toString() + " " + expr2->toString());
    return str;
}

Arith::~Arith(){
    delete tempPtr;
    tempPtr = nullptr;
}
