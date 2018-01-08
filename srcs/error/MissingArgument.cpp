#include <MissingArgument.hpp>

MissingArgument::MissingArgument(const std::string &funct) : _funct(funct) {
}

MissingArgument::MissingArgument() : _funct("") {
}

MissingArgument::~MissingArgument() {
}

MissingArgument::MissingArgument(MissingArgument const & src) : _funct(src._funct) {
}

MissingArgument& MissingArgument::operator=(MissingArgument const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char * MissingArgument::what() const throw ()
{
	return ("Error :  Missing argument error with  line ' "+_funct+" '").c_str();
}