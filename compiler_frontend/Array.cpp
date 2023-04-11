#include "Array.h"

Array::Array(int sz, Type *p)
: Type("[]", Tag::INDEX, sz*(p->width)), size(sz), of(p)
{}


std::string Array::toString() const{
    std::string str("[" + std::to_string(size) + "] " + of->toString());
    return str;
}
