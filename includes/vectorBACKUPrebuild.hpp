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
			//constructor
			explicit vector(const allocator_type& alloc = allocator_type())
			: _vector(0), _size(0), _size_fill(0), _alloc(alloc){
				_vector = _alloc.allocate(0);
			};
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) 
			: _vector(0), _size(n), _size_fill(0), _alloc(alloc){
				_vector = _alloc.allocate(0);
				insert(begin(), n, val);
			};
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _vector(0), _size(0), _size_fill(0), _alloc(alloc){
				this->_vector = this->_alloc.allocate(0);
				assign(first, last);
			};
			vector (const vector& x){
				*this = x;
			};
			vector &operator=(const vector &copy) {
				if (this->_vector != 0)
					this->_alloc.deallocate(this->_vector, this->_size);
				this->_size = copy._size;
				this->_size_fill = copy._size_fill;
				this->_alloc = copy.get_allocator();
				this->_vector = this->_alloc.allocate(0);
				assign(copy.begin(), copy.end());
				return (*this);
			}
			///////////////////////////////////////
			//			Iterators:               //
			///////////////////////////////////////
			iterator		begin(){
				return (iterator(&this->_vector[0]));
			};
			const_iterator	begin() const{
				return (const_iterator(&this->_vector[0]));
			};
			iterator end(){
				return (iterator(&this->_vector[this->_size_fill]));
			};
			const_iterator end() const{
				return (const_iterator(&this->_vector[this->_size_fill]));
			};
			reverse_iterator rbegin(){
				return(reverse_iterator(&this->_vector[this->_size_fill]));
			}
			const_reverse_iterator rbegin() const{
				return(const_reverse_iterator(&this->_vector[this->_size_fill]));
			};
			reverse_iterator rend(){
				return(reverse_iterator(&this->_vector[0]));
			};
			const_reverse_iterator rend() const {
				return(const_reverse_iterator(&this->_vector[0]));
			};
			///////////////////////////////////////
			//			Capacity:               //
			///////////////////////////////////////
			size_type size() const{
				return (this->_size_fill);
			};
			size_type max_size() const{
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			};
			void resize (size_type n, value_type val = value_type()){
				pointer rep;
				rep = this->_alloc.allocate(n);
				for(size_type i = 0; i < this->_size_fill; i++){
					rep[i] = this->_vector[i];
				}
				for(size_type i = this->_size_fill; i < this->_size; i++){
					rep[i] = val;
				}
				this->_alloc.deallocate(this->_vector, this->_size);
				this->_vector = rep;
				this->_size = n;
			};
			size_type capacity() const{
				return (this->_size);
			};
			bool empty() const {
				return(this->_size_fill == 0);
			};
			void reserve (size_type n){
				if (n > this->_size)
				{
				T	*dupli = new T[n - 1];
				for (size_type i = 0; i < this->_size; ++i)
				{
					dupli[i] = this->_vector[i];
					std::cout << dupli[i] << " " << this->_vector[i] << std::endl;
				}
				for (size_type i = 0; i < this->_size; ++i)
					this->_alloc.destroy(this->_vector + i);
				this->_alloc.deallocate(this->_vector, this->_size);
				this->_vector = nullptr;
				this->_size += 1;
				this->_vector = this->_alloc.allocate(this->_size);
				for(size_type i = 0; i < this->_size; ++i)
					this->_alloc.construct(this->_vector + i, dupli[i]);
				delete[] dupli;
				}
				// for(size_type i = 0; i <= this->_size_fill; i++){
				// 	rep[i] = this->_vector[i];
				// }
				// std::cout << "deal" << std::endl;
				// this->_alloc.deallocate(this->_vector, this->_size);
				// this->_size = n;
				// this->_vector = rep;
			};
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