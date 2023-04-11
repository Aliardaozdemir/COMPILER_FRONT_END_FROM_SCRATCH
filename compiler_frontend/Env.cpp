#include "Env.h"

Env::Env(Env *n)
: prev(n)
{}

void Env::put(Token *w, Id *i){
    table.put(w, i);
}

Id* Env::get(Token *w){
    for(Env *e = this; e != nullptr; e = e->prev){
        Id *found = e->table.get(w);
        if(found != nullptr)
            return found;
    }
    return nullptr;
}
