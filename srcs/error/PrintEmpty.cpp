#include <PrintEmpty.hpp>

PrintEmpty::PrintEmpty() {
}

PrintEmpty::~PrintEmpty() {
}

PrintEmpty::PrintEmpty(PrintEmpty const & src) {
	*this = src;
}

PrintEmpty& PrintEmpty::operator=(PrintEmpty const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char * PrintEmpty::what() const throw ()
{
	return ("Error :  Print on empty stack ");
}