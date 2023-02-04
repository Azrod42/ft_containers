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
		//constructor
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		vector (const vector& x);
		//destructor
		~vector();
		//operator
		vector		&operator=(const vector<T> &copy);
};
#endif