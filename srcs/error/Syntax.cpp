#include <Syntax.hpp>

Syntax::Syntax(const std::string &line) : _line(line) {
}

Syntax::Syntax() : _line("") {
}

Syntax::~Syntax() {
}

Syntax::Syntax(Syntax const & src) : _line(src._line) {
}

Syntax& Syntax::operator=(Syntax const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char * Syntax::what() const throw ()
{
	return ("Error :  Syntax error with  line ' "+_line+" '").c_str();
}