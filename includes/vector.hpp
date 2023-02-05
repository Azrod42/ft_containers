#ifndef VECTOR_HPP
# define VECTOR_HPP

# include<iostream>
# include<cmath>
# include<cstdio>
# include"iteratorv.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T*					pointer;
			typedef T					value_type;
			typedef size_t				size_type;
			typedef Alloc				allocator_type;	
			typedef ft::Iteratorv<T> 	iterator;
			typedef ft::Citeratorv<T> 	const_iterator;
			typedef ft::Riteratorv<T> 	reverse_iterator;

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
			iterator		begin(){
				return (iterator(this->_vector));
			};
			const_iterator	begin() const{
				return (const_iterator(this->_vector));
			};
			iterator end(){
				iterator it(this->_vector);
				while (it)
					it++;
				it--;
				return (it);
			};
			const_iterator end() const;
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