#ifndef NUM_H
#define NUM_H

#include "Token.h"

class Num : public Token{
public:
    explicit Num(int v);
    std::string toString() const;
    
    const int value;
};

#endif
