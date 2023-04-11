#include "Word.h"


Word::Word(std::string s, int tag)
: Token(tag), lexeme(s)
{}

std::string Word::toString() const{
    return lexeme;
}


Word Word::and_v("&&", Tag::AND);
Word Word::or_v("||", Tag::OR);
Word Word::eqv("==", Tag::EQ);
Word Word::nev("!=", Tag::NE);
Word Word::lev("<=", Tag::LE);
Word Word::gev(">=", Tag::GE);
Word Word::minusv("minus", Tag::MINUS);
Word Word::Truev("true", Tag::TRUE);
Word Word::Falsev("false", Tag::FALSE);
Word Word::tempv("t", Tag::TEMP);

Word *const Word::and_ = &and_v;
Word *const Word::or_ = &or_v;
Word *const Word::eq = &eqv;
Word *const Word::ne = &nev;
Word *const Word::le = &lev;
Word *const Word::ge = &gev;
Word *const Word::minus = &minusv;
Word *const Word::True = &Truev;
Word *const Word::False = &Falsev;
Word *const Word::temp = &tempv;
