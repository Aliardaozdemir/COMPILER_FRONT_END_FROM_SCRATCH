#include "EnvTable.h"

EnvTable::EnvTable(){
    t = new EnvEntry *[TABLE_SIZE];
    
    for(int i = 0; i < TABLE_SIZE; i++){
        t[i] = nullptr;
    }
}


int EnvTable::h1(Token *k) const{
    uintptr_t val = (uintptr_t)k;
    int temp = (int)val;
    return val % TABLE_SIZE;
}

int EnvTable::hashFunc(int k){
    return k % TABLE_SIZE;
}

void EnvTable::put(Token *k, Id *v){
    int h = h1(k);
    
    while(t[h] != nullptr && t[h]->k != k){
        h = hashFunc(h + 1);
    }
    
    if(t[h] != nullptr)
        delete t[h];
    
    t[h] = new EnvEntry(k,v);
}

Id* EnvTable::get(Token *k){
    int h = h1(k);
    
    while(t[h] != nullptr && t[h]->k != k){
        h = hashFunc(h + 1);
    }
    
    if(t[h] == nullptr)
        return nullptr;
    else
        return t[h]->v;
}

EnvTable::~EnvTable(){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(t[i] != nullptr)
            delete t[i];
    }
    delete [] t;
}
