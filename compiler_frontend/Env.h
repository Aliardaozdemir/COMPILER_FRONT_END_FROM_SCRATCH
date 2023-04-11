#ifndef ENV_H
#define ENV_H

#include "EnvTable.h"
#include "Token.h"
#include "Id.h"

class Env{
public:
    Env(Env *n);
    void put(Token *w, Id *i);
    Id* get(Token *w);
    
    Env *prev;
private:
    EnvTable table;
};

#endif
