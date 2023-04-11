#include "Do.h"

Do::Do()
: expr(nullptr), stmt(nullptr)
{}

void Do::init(Stmt *s, Expr *x){
    expr = x;
    stmt = s;
    
    if( expr->type != Type::Bool )
        expr->error("bool required in do");
}

void Do::gen(int b, int a){
    after = a;
    int label = newlabel();
    stmt->gen(b, label);
    emitlabel(label);
    expr->jumping(b,0);
}
