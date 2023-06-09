#ifndef TAG_H
#define TAG_H

class Tag{
public:
    static const int AND = 256;
    static const int BASIC = 257;
    static const int BREAK = 258;
    static const int DO = 259;
    static const int ELSE = 260;
    static const int EQ = 261;
    static const int FALSE = 262;
    static const int GE = 263;
    static const int ID = 264;
    static const int IF = 265;
    static const int INDEX = 266; //NOT LEXICAL WILL BE USED IN SYNTAX TREE
    static const int LE = 267;
    static const int MINUS = 268; //NOT LEXICAL WILL BE USED IN SYNTAX TREE
    static const int NE = 269;
    static const int NUM = 270;
    static const int OR = 271;
    static const int REAL = 272;
    static const int TEMP = 273; //NOT LEXICAL WILL BE USED IN SYNTAX TREE
    static const int TRUE = 274;
    static const int WHILE = 275;
    
};


#endif
