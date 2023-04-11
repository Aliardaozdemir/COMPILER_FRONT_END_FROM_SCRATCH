#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <string>
#include "Word.h"

const int T_S = 1000;

class HashEntry{
public:
    HashEntry(std::string key, Word *value);
    std::string k;
    Word *v;
};

#endif
