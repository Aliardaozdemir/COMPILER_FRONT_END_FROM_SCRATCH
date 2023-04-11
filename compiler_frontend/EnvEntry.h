#ifndef ENVENTRY_H
#define ENVENTRY_H

const int TABLE_SIZE = 1000;

#include "Token.h"
#include "Id.h"

class EnvEntry{
public:
    
    EnvEntry(Token *key, Id *value);
    
    Token *k;
    Id *v;
    
};

#endif
