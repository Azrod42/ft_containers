#ifndef VECTOR_HPP
# define VECTOR_HPP

# include<iostream>

template < typename T, class Alloc = std::allocator<T> >
class vector {
	private:
		T*				_vector;
		size_t			_size;
		allocator_type	_allocator;

	public:
		vector();
		vector(const vector<T> &copy);
		~vector();
	
		vector		&operator=(const vector<T> &copy);
};
#endif