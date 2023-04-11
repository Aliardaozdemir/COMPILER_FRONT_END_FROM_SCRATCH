#include "While.h"

While::While()
: expr(nullptr), stmt(nullptr)
{}

void While::init(Expr *x, Stmt *s){
    expr = x;
    stmt = s;
    if( expr->type != Type::Bool )
        expr->error("bool required in while");
}

void While::gen(int b, int a){
    after = a;
    expr->jumping(0, a);
    int label = newlabel();
    emitlabel(label);
    stmt->gen(label, b);
    emit_("goto L" + std::to_string(b));
}
