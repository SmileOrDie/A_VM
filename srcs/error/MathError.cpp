#include <MathError.hpp>

MathError::MathError(const std::string &operation) : _operation(operation) {
}

MathError::MathError() : _operation("") {
}

MathError::~MathError() {
}

MathError::MathError(MathError const & src) : _operation(src._operation) {
}

MathError& MathError::operator=(MathError const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char * MathError::what() const throw ()
{
	return ("Error :  Stack too little for operation ' "+_operation+" '").c_str();
}