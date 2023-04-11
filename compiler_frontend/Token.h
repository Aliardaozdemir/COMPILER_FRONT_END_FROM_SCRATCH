#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "Tag.h"

class Token{
public:
    explicit Token(int t);
    std::string toString() const;
    virtual void dummy(){return;}
    
    const int tag;
};


#endif
