#ifndef ENVTABLE_H
#define ENVTABLE_H

#include "EnvEntry.h"
#include <cstdlib>
#include <cstdio>

class EnvTable{
public:
    EnvTable();
    int h1(Token *k) const;
    int hashFunc(int k);
    void put(Token *k, Id *v);
    Id* get(Token *k);
    ~EnvTable();
    
private:
    EnvEntry **t;
};

#endif
