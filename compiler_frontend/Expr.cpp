#include "Expr.h"

Expr::Expr(Token *tok, Type *p)
: op(tok), type(p)
{
    //
}

Expr* Expr::gen(){
    return this;
}

Expr* Expr::reduce(){
    return this;
}

void Expr::jumping(int t, int f){
    emitjumps(toString(), t, f);
}

void Expr::emitjumps(std::string test, int t, int f){
    if( t != 0 && f != 0 ){
        emit_("if " + test + " goto L" + std::to_string(t));
        emit_("goto L" + std::to_string(f));
    }
    else if( t != 0 )
        emit_("if " + test + " goto L" + std::to_string(t));
    else if( f != 0 )
        emit_("iffalse " + test + " goto L" + std::to_string(f));
    else;
}

std::string Expr::toString() const{
    return op->toString();
}








