#ifndef REAL_H
#define REAL_H

#include "Token.h"

class Real : public Token{
public:
    explicit Real(float v);
    std::string toString() const;
    
    const float value;
};

#endif
