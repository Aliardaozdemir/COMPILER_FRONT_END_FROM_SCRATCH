#include "Logical.h"

Logical::Logical(Token *tok, Expr *x1, Expr *x2)
: Expr(tok, nullptr), expr1(x1), expr2(x2), tempPtr(nullptr)
{
    Type *ptr = check(expr1->type, expr2->type);
    if(ptr == nullptr)
        error("type error");
}


Type* Logical::check(Type *p1, Type *p2){
    if( p1 == Type::Bool && p2 == Type::Bool )
        return Type::Bool;
    else return nullptr;
}


Expr* Logical::gen(){
    int f = newlabel();
    int a = newlabel();
    
    tempPtr = new Temp(type);
    
    this->jumping(0,f);
    emit_(tempPtr->toString() + " = true");
    emit_("goto L"+ std::to_string(a));
    emitlabel(f);
    emit_(tempPtr->toString() + " = false");
    emitlabel(a);
    return tempPtr;
    
}

std::string Logical::toString() const{
    std::string str(expr1->toString() + " " + op->toString() + " " + expr2->toString());
    return str;
}

Logical::~Logical(){
    delete tempPtr;
    tempPtr = nullptr;
}
