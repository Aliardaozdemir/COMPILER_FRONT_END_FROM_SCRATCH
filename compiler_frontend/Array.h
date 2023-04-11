#ifndef ARRAY_H
#define ARRAY_H

#include "Type.h"

class Array : public Type{
public:
    Array(int sz, Type *p);
    std::string toString() const;
    
    int size = 1;
    Type *of;
};


#endif
