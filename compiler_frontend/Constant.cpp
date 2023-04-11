#include "Constant.h"

Constant::Constant(Token *tok, Type *p)
: Expr(tok, p), tempPtr(nullptr)
{}

Constant::Constant(int i)
: tempPtr(new Num(i)), Expr(tempPtr, Type::Int)
{}

void Constant::jumping(int t, int f){
    if( this == True && t != 0 )
        emit_("goto L" + std::to_string(t));
    else if( this == False && f != 0)
        emit_( "goto L" + std::to_string(f));
}

Constant::~Constant(){
    delete tempPtr;
    tempPtr == nullptr;
}

Constant Constant::Truev(Word::True, Type::Bool);
Constant Constant::Falsev(Word::False, Type::Bool);

Constant *const Constant::True = &Truev;
Constant *const Constant::False = &Falsev;
