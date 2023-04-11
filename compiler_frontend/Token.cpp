#include "Token.h"

Token::Token(int t)
: tag(t)
{}

std::string Token::toString() const{
    std::string str("");
    str += (char)tag;
    return str;
}
