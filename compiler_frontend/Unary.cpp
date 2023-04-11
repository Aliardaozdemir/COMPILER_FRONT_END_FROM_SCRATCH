#include "Unary.h"

Unary::Unary(Token *tok, Expr *x)
: Op(tok, nullptr), expr(x), tempPtr(nullptr)
{
    Type *ptr = Type::max(Type::Int, expr->type);
    if(ptr == nullptr)
        error("type error");
}

Expr* Unary::gen(){
    tempPtr = new Unary(op, expr->reduce());
    return tempPtr;
}

std::string Unary::toString() const{
    std::string str(op->toString() + " " + expr->toString());
    return str;
}

Unary::~Unary(){
    delete tempPtr;
    tempPtr = nullptr;
}
