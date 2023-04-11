#ifndef NODE_h
#define NODE_H

#include <string>
#include <stdexcept>
#include <iostream>
#include "Lexer.h"

class Node{
public:
    
    Node();
    void error(std::string s);
    int newlabel();
    void emitlabel(int i);
    void emit_(std::string s);
    
    static int labels;
    int lexline = 0;
};

#endif
