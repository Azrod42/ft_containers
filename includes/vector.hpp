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
			typedef T&					reference;
			typedef const T&			const_reference;
			typedef T					value_type;
			typedef size_t				size_type;
			typedef Alloc				allocator_type;	
			typedef ft::Iteratorv<T> 	iterator;
			typedef ft::Citeratorv<T> 	const_iterator;
			typedef ft::Riteratorv<T> 	reverse_iterator;
			typedef ft::CRiteratorv<T> 	const_reverse_iterator;

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
			///////////////////////////////////////
			//			Iterators:               //
			///////////////////////////////////////
			iterator		begin(){
				return (iterator(this->_vector));
			};
			const_iterator	begin() const{
				return (const_iterator(this->_vector));
			};
			iterator end(){
				return (iterator(this->_vector + this->_size_fill));
			};
			const_iterator end() const{
				return (const_iterator(this->_vector + this->_size_fill));
			};
			reverse_iterator rbegin(){
				return(reverse_iterator(this->_vector));
			}
			const_reverse_iterator rbegin() const{
				return(const_reverse_iterator(this->_vector));
			};
			reverse_iterator rend(){
				return(reverse_iterator(this->_vector + this->_size_fill));
			};
			const_reverse_iterator rend() const {
				return(const_reverse_iterator(this->_vector + this->_size_fill));
			};
			const_iterator cbegin() const {
				return (const_iterator(this->_vector));
			};
			const_iterator cend() const {
				return (const_iterator(this->_vector + this->_size_fill));
			};
			const_reverse_iterator crbegin() const {
				return(const_reverse_iterator(this->_vector));
			};
			const_reverse_iterator crend() const{
				return (const_reverse_iterator(this->_vector + this->_size_fill));
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
			size_type capacity() const;
			bool empty() const {
				return(this->_size_fill == 0);
			};
			void reserve (size_type n){
				if (n < this->_size)
					return ;
				pointer rep = this->_alloc.allocate(n);
				for(size_type i = 0; i <= this->_size_fill; i++){
					rep[i] = this->_vector[i];
				}
				this->_alloc.deallocate(this->_vector, this->_size);
				this->_size = n;
				this->_vector = rep;
			};
			void shrink_to_fit();
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
					reserve((this->_size + 1));
				}
				this->_vector[this->_size_fill] = val;
				this->_size_fill += 1;
			};
			void pop_back();
			iterator insert(iterator position, const value_type& val){
					size_type i = 0;

					for (iterator it = begin(); it + i != position && i < this->_size_fill; i++){};
					if (this->_size < this->_size_fill + 1)
						reserve(this->_size_fill + 1);
					for(size_type j = this->_size - 1; j > i; j--) {
						this->_vector[j] = this->_vector[j - 1];
					}
					this->_vector[i] = val;
					this->_size_fill++;
					return (iterator(&this->_vector[i]));
			};
			void insert (iterator position, size_type n, const value_type& val){
				for(size_type i = 0; i < n; i++){
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
				
			};
			iterator erase (iterator first, iterator last);
			void swap (vector& x);
			void clear(){
				if (this->_size){
					this->_alloc.deallocate(this->_vector, this->_size);
					this->_vector = this->_alloc.allocate(0);
					this->_size = 0;
				} 
			};
			//emplace
			//emplace_back
			///////////////////////////////////////
			//			  Allocator:             //
			///////////////////////////////////////
			allocator_type get_allocator() const;
	};
}
#endif