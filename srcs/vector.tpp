#include"../../include/vector.hpp"

vector::vector() _{
	std::cout << "Constructor called" << std::endl;
	return ;
}

vector::~vector() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

vector::vecor(const vector &copy) {
	*this = copy;
}

vector		&vector::operator=(const vector &copy) {
	*this = copy;
	return (*this);
}