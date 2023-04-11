#include "Type.h"

Type::Type(std::string s, int tag, int w)
: Word(s, tag), width(w)
{}

bool Type::numeric(Type *p){
    if( p == Type::Char || p == Type::Int || p == Type::Float )
        return true;
    else
        return false;
}

Type* Type::max(Type *p1, Type *p2){
    if( !numeric(p1) || !numeric(p2) )
        return nullptr;
    else if( p1 == Type::Float || p2 == Type::Float )
        return Type::Float;
    else if( p1 == Type::Int || p2 == Type::Int )
        return Type::Int;
    else 
        return Type::Char;
}


Type Type::Intv("int", Tag::BASIC, 4);
Type Type::Floatv("float", Tag::BASIC, 8);
Type Type::Charv("char", Tag::BASIC, 1);
Type Type::Boolv("bool", Tag::BASIC, 1);

Type *const Type::Int = &Intv;
Type *const Type::Float = &Floatv;
Type *const Type::Bool = &Boolv;
Type *const Type::Char = &Charv;
