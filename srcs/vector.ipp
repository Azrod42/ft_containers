#include "../includes/vector.hpp"

vector::vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0){
	std::cout << "Constructor called" << std::endl;
	this->_vector = this->_alloc.
	return ;
}

// vector::~vector() {
// 	std::cout << "Destructor called" << std::endl;
// 	return ;
// }

// vector::vecor(const vector &copy) {
// 	*this = copy;
// }

// vector		&vector::operator=(const vector &copy) {
// 	*this = copy;
// 	return (*this);
// }