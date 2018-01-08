#include <Print.hpp>

Print::Print() {
}

Print::~Print() {
}

Print::Print(Print const & src) {
	*this = src;
}

Print& Print::operator=(Print const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char *Print::what() const throw () { return ("Error :  Print"); }