#ifndef VECTOR_HPP
# define VECTOR_HPP

# include<iostream>
# include<cmath>
# include<cstdio>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T*		pointer;
			typedef T		value_type;
			typedef size_t	size_type;
			typedef Alloc	allocator_type;	

		private:
			pointer			_vector;
			size_type		_size;
			allocator_type	_alloc;

		public:
			//constructor
			explicit vector(const allocator_type& alloc = allocator_type())
			: _vector(0), _size(0), _alloc(alloc){
				std::cout << "Constructor default" << std::endl;
				_vector = _alloc.allocate(0);
			};
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) 
			: _vector(0), _size(n), _alloc(alloc){
				std::cout << "Constructor size" << std::endl;
				_vector = _alloc.allocate(_size);
				(void)val;
			};
			// explicit vectoc,czm                    size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			// template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			// vector (const vector& x);
			//destructor
			// ~vector();
			//operator
			// vector		&operator=(const vector<T> &copy);
	};
}
#endif