#ifndef VECTOR_HPP
# define VECTOR_HPP

# include<iostream>
# include<cmath>
# include<cstdio>
# include"ft_include.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;	
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef ft::random_access_iterator_tag<T> 				iterator;
			typedef ft::random_access_iterator_tag<const T> 		const_iterator;
			typedef ft::reverse_iterator<T> 						reverse_iterator;
			typedef ft::reverse_iterator<const T> 					const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef size_t											size_type;

		private:
			pointer			_vector;
			size_type		_size;
			size_type		_size_fill;
			allocator_type	_alloc;

		public:
			///////////////////////////////////////
			//			Iterators:               //
			///////////////////////////////////////
			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); 
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x);
			vector &operator=(const vector &copy);
			~vector();
			///////////////////////////////////////
			//			Iterators:               //
			///////////////////////////////////////
			iterator				begin();
			const_iterator			begin() const;
			iterator 				end();
			const_iterator			end() const;
			reverse_iterator 		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const ;
			///////////////////////////////////////
			//			Capacity:               //
			///////////////////////////////////////
			size_type size() const;
			size_type max_size() const;
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve (size_type n);
			///////////////////////////////////////
			//			Element access:          //
			///////////////////////////////////////
			reference operator[] (size_type n){
				return(this->_vector[n]);
			};
			const_reference operator[] (size_type n) const{
				return (*this->_vector[n]);
			};
			reference at (size_type n) {
				return (this->_vector[n]);
			};
			const_reference at (size_type n) const {
				return (*this->_vector[n]);
			};
			reference front(){
				return (this->_vector[0]);
			};
			const_reference front() const {
				return (*this->_vector[0]);
			};
			reference back(){
				return (this->_vector[this->_size_fill - 1]);
			};
			const_reference back() const {
				return (*this->_vector[this->_size_fill - 1]);
			};
			value_type* data() {
				return (this->_vector);
			};
			const value_type* data() const {
				return (this->_vector);
			};
			///////////////////////////////////////
			//			  Modifiers:             //
			///////////////////////////////////////
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last){
				clear();
				insert(begin(), first, last);	
			};
			void assign (size_type n, const value_type& val){
				clear();
				insert(begin(), n, val);
			};
			void push_back (const value_type& val){
				if (this->_size_fill + 1 > this->_size)
				{
					std::cout << "reserve, size = "<< this->_size << " fill : " << this->_size_fill << std::endl;
					reserve((this->_size + 1));
					std::cout << "out reserve" << std::endl;
				}
				this->_vector[this->_size_fill] = val;
				this->_size_fill += 1;
			};
			void pop_back(){
				if (this->_size_fill)
					this->_size_fill--;
			};
			iterator insert(iterator position, const value_type& val){
					size_type i = 0;
					iterator	it = begin();

					if (this->_size < this->_size_fill + 1)
						reserve(this->_size_fill + 1);
					while (it + i != position)
						i++;
					if (this->_size_fill){
					for (size_type j = this->_size_fill - 1; j > i; j--)
					{
						this->_vector[j] = this->_vector[j - 1];
					}
					}
					this->_vector[i] = val;
					this->_size_fill++;
					return(iterator(&this->_vector[i]));
					// while  (begin() != position)
					// 	i++;
					// pointer	ret = &this->_vector[i];
					// if (this->_size < this->_size_fill + 1)
					// 	reserve(this->_size_fill + 1);
					// if (i != this->_size) 
					// 	std::copy(position, end(), ret);
					// this->_alloc.construct(this->_vector[i], val);
					// this->_size_fill++;
					// return (iterator(&this->_vector[i]));
			};
			void insert (iterator position, size_type n, const value_type& val){
				for(size_type i = 0; i <= n; i++){
					insert(position, val);
				}
			};

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last){
				while (first != last){
					position = (insert(position, *first)) + 1;
					++first;
				} 
			};
			iterator erase (iterator position){
				iterator	it = position;

				while ((it + 1) != end())
					{
						*it = *(it + 1);
						it++;
					}
					*(it + 1) = 0;
				this->_size_fill -= 1;
				return (iterator(position));
			};
			iterator erase (iterator first, iterator last){
				size_type i = 0;

				while (first + i != last)
				 	i++;
				while (i > 0) {
					erase(first);
					i--;
				}
				return (iterator(first));
			};
			void swap (vector& x);
			void clear(){
				if (this->_size){
					this->_alloc.deallocate(this->_vector, this->_size);
					this->_vector = this->_alloc.allocate(0);
					this->_size = 0;
				} 
			};
			///////////////////////////////////////
			//			  Allocator:             //
			///////////////////////////////////////
			allocator_type get_allocator() const{
				allocator_type ret = this->_alloc;
				return (ret);
			};
	};
}
#endif