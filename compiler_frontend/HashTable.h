#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashEntry.h"
#include <functional>
#include <cstdlib>
#include <cstdio>


class HashTable{
public:
    HashTable();
    int h1(std::string k);
    int hashFunc(int k);
    void put(std::string k, Word *p);
    Word* get(std::string k);
    ~HashTable();
    
private:
    HashEntry **t;
};

#endif
