#include "Temp.h"

int Temp::count = 0;

Temp::Temp(Type *p)
: Expr(Word::temp, p), number(++count)
{}

std::string Temp::toString() const{
    std::string str("t" + std::to_string(number));
    return str;
}
