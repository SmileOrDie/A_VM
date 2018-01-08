#include <ExtraArgument.hpp>

ExtraArgument::ExtraArgument(const std::string &funct, const std::string &arg) : _funct(funct), _arg(arg) {
}

ExtraArgument::ExtraArgument() : _funct(""), _arg("") {
}

ExtraArgument::~ExtraArgument() {
}

ExtraArgument::ExtraArgument(ExtraArgument const & src) : _funct(src._funct), _arg(src._arg) {
}

ExtraArgument& ExtraArgument::operator=(ExtraArgument const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char * ExtraArgument::what() const throw ()
{
	return ("Error :  Extra argument  ' "+_arg+" ' error with  function ' "+_funct+" '").c_str();
}