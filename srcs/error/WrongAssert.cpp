#include <WrongAssert.hpp>

WrongAssert::WrongAssert() {

}

WrongAssert::~WrongAssert() {

}

WrongAssert::WrongAssert(WrongAssert const & src) {
	*this = src;
}

WrongAssert& WrongAssert::operator=(WrongAssert const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char *WrongAssert::what() const throw () { return ("Error :  WrongAssert "); }