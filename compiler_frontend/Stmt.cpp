#include "Stmt.h"

Stmt::Stmt()
{}

void Stmt::gen(int b, int a){}

Stmt* Stmt::Null = new Stmt();
Stmt* Stmt::Enclosing = Null;
