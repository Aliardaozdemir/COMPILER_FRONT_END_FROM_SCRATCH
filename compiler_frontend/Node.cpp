#include "Node.h"

int Node::labels = 0;

Node::Node()
: lexline(Lexer::line)
{}

void Node::error(std::string s){
    if(true)
        throw std::invalid_argument("near line " + std::to_string(lexline) + ": " + s);
}

int Node::newlabel(){
    return ++labels;
}

void Node::emitlabel(int i){
    std::cout << "L" << i << ":";
}

void Node::emit_(std::string s){
    std::cout << "\t" << s << std::endl;
}
