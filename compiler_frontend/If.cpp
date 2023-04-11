#include "If.h"


If::If(Expr *x, Stmt *s)
: expr(x), stmt(s)
{
    if(expr->type != Type::Bool)
        expr->error("bool value required in if");
}

void If::gen(int b, int a){
    int label = newlabel();
    
    expr->jumping(0, a);
    emitlabel(label);
    stmt->gen(label, a);
}
