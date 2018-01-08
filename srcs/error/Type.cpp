#include <Type.hpp>

Type::Type() {

}

Type::~Type() {

}

Type::Type(Type const & src) {
	*this = src;
}

Type& Type::operator=(Type const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char *Type::what() const throw () { return ("Error :  Unknown type "); }