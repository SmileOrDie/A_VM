#include <LexicalType.hpp>

LexicalType::LexicalType(const std::string &line) : _line(line) {
}

LexicalType::LexicalType() : _line("") {
}

LexicalType::~LexicalType() {
}

LexicalType::LexicalType(LexicalType const & src) : _line(src._line) {
}

LexicalType& LexicalType::operator=(LexicalType const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char * LexicalType::what() const throw ()
{
	return ("Error :  Lexical error with  type ' "+_line+" '").c_str();
}