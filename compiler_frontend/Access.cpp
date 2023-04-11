#include "Access.h"

Access::Access(Id *a, Expr *i, Type *p)
: temp1(new Word("[]", Tag::INDEX)), temp2(nullptr), Op(temp1, p), array(a), index(i)
{}

Expr* Access::gen(){
    temp2 = new Access(array, index->reduce(), type);
    return temp2;
}

void Access::jumping(int t, int f){
    emitjumps(reduce()->toString(), t, f);
}

std::string Access::toString() const{
    std::string str( array->toString() + " [ " + index->toString() + " ]");
    return str;
}

Access::~Access(){
    delete temp1;
    temp1 = nullptr;
    delete temp2;
    temp2 = nullptr;
}
