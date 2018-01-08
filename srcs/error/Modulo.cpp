#include <Modulo.hpp>

Modulo::Modulo() {
}

Modulo::~Modulo() {
}

Modulo::Modulo(Modulo const & src) {
	*this = src;
}

Modulo& Modulo::operator=(Modulo const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char *Modulo::what() const throw () { return ("Error :  Modulo"); }