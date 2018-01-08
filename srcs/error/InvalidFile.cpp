#include <InvalidFile.hpp>

InvalidFile::InvalidFile() {
}

InvalidFile::~InvalidFile() {
}

InvalidFile::InvalidFile(InvalidFile const & src) {
	*this = src;
}

InvalidFile& InvalidFile::operator=(InvalidFile const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char * InvalidFile::what() const throw ()
{
	return "Error :  Invalid file ";
}