#include "Lexer.h"
#include "Parser.h"
#include <iostream>

int main(){
    Lexer *lex = new Lexer();
    Parser *parse = new Parser(lex);
    parse->program();
    std::cout << "\n" ;
    
    delete lex;
    delete parse;
}
