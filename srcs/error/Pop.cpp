#include <Pop.hpp>

Pop::Pop() {
}

Pop::~Pop() {
}

Pop::Pop(Pop const & src) {
	*this = src;
}

Pop& Pop::operator=(Pop const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char *Pop::what() const throw () { return ("Error :  Pop on empty stack"); }