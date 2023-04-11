#include "HashTable.h"

using namespace std;

hash<string> hasher;

HashTable::HashTable(){
    t = new HashEntry *[T_S];
    
    for(int i = 0; i < T_S ; i++){
        t[i] = nullptr;
    }
}

int HashTable::h1(string k){
    unsigned int t = hasher(k);
    int h = (int)t;
    return h % T_S;
}

int HashTable::hashFunc(int k){
    return k % T_S;
}

void HashTable::put(string k, Word *v){
    int h = h1(k);
    
    while(t[h] != nullptr && t[h]->k != k){
        h = hashFunc(h + 1);
    }
    
    if(t[h] != nullptr)
        delete t[h];
    t[h] = new HashEntry(k,v);
}

Word* HashTable::get(std::string k){
    int h = h1(k);
    
    while(t[h] != nullptr && t[h]->k != k){
        h = hashFunc(h + 1);
    }
    
    if(t[h] == nullptr)
        return nullptr;
    else
        return t[h]->v;
}

HashTable::~HashTable(){
    for(int i = 0; i < T_S ; i++){
        if(t[i] != nullptr);
        delete t[i];
    }
    
    delete [] t;
}


