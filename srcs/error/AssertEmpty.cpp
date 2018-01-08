#include <AssertEmpty.hpp>

AssertEmpty::AssertEmpty() {
}

AssertEmpty::~AssertEmpty() {
}

AssertEmpty::AssertEmpty(AssertEmpty const & src) {
	*this = src;
}

AssertEmpty& AssertEmpty::operator=(AssertEmpty const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}


const char * AssertEmpty::what() const throw ()
{
	return ("Error :  Assert on empty stack ");
}