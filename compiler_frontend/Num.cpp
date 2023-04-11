#include "Num.h"

Num::Num(int v)
: Token(Tag::NUM), value(v)
{
    //
}

std::string Num::toString() const{
    std::string str("" + std::to_string(value));
    return str;
}
