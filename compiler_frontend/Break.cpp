#include "Break.h"

Break::Break()
{
    if(Stmt::Enclosing == nullptr)
        error("unenclosed break");
    stmt = Stmt::Enclosing;
}

void Break::gen(int b, int a){
    emit_("goto L" + stmt->after);
}






