#include "Real.h"

Real::Real(float v)
: Token(Tag::REAL), value(v)
{
    //
}

std::string Real::toString() const{
    std::string str("" + std::to_string(value));
    return str;
}
