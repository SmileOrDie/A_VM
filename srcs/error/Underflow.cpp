#include <Underflow.hpp>

Underflow::Underflow(const int &a) : _a(a), _b(0), _operation("") {
}

Underflow::Underflow(const int &a, const int &b, const std::string &operation) : _a(a), _b(b), _operation(operation) {
}

Underflow::Underflow() : _a(0), _b(0), _operation("") {
}

Underflow::~Underflow() {

}

Underflow::Underflow(Underflow const & src) : _a(src._a), _b(src._b), _operation(src._operation) {
}

Underflow& Underflow::operator=(Underflow const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char *Underflow::what() const throw () {
	if (_operation == "")
		return ("Error : Underflow with "+std::to_string(_a)).c_str();
	else
		return ("Error : Underflow with "+std::to_string(_a)+" "+_operation+" "+std::to_string(_b)+" ").c_str();
}
