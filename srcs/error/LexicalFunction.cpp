#include <LexicalFunction.hpp>

LexicalFunction::LexicalFunction(const std::string &line) : _line(line) {
}

LexicalFunction::LexicalFunction() : _line("") {
}

LexicalFunction::~LexicalFunction() {
}

LexicalFunction::LexicalFunction(LexicalFunction const & src) : _line(src._line) {
}

LexicalFunction& LexicalFunction::operator=(LexicalFunction const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char * LexicalFunction::what() const throw ()
{
	return ("Error :  Lexical error with  function ' "+_line+" '").c_str();
}