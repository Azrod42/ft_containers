#ifndef VECTOR_TPP
# define VECTOR_TPP

#include"vector.hpp"

using namespace ft;
			
template <typename T, class Alloc>
vector<T, Alloc>::vector (const allocator_type& alloc)
: _size(0), _size_fill(0), _tab(NULL), _alloc(alloc){
	return ;
};
template <typename T, class Alloc>
vector<T, Alloc>::vector (size_type n, const value_type& val, const allocator_type& alloc)
: _size(n), _size_fill(n), _alloc(alloc){
	if (n == 0){
		this->_tab = NULL;
	}
	else if (n > 0) {
		this->_tab = this->_alloc.allocate(this->_size);
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.construct(this->_tab + i, val);
	}
	else 
		throw std::invalid_argument("Error : Invalid number\n");
}; 

template <typename T, class Alloc>
template <class InputIterator>
vector<T, Alloc>::vector (InputIterator first, InputIterator last, const allocator_type& alloc)
: _size(0), _size_fill(0), _tab(NULL), _alloc(alloc){
	size_type n = (size_type)((difference_type)last - (difference_type)first);
	
	if (n > 0){
		this->_size = n;
		this->_size_fill = n;
		this->_tab = this->_alloc.allocate(n);
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.construct(this->_tab + i, *(first + i));
	}
	else{
		this->_size = 0;
		this->_size_fill = 0;
		this->_tab = NULL;
	}

};
template <typename T, class Alloc>
vector<T, Alloc>::vector (const vector& x)
: _size(0), _size_fill(0), _tab(NULL){
	*this = x;
};
template <typename T, class Alloc>
vector<T, Alloc> &vector<T, Alloc>::operator=(const vector &copy){
	if (this->_size_fill)
	{
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_tab + i);
		this->_alloc.deallocate(this->_tab, this->_size);
	}
	this->_size = copy.size;
	this->_size_fill = copy._size_fill;
	if (this->_size > 0){
		this->_tab = this->_alloc.allocate(this->_size);
		for(size_type i = 0; i < this->_size; i++)
			this->_tab[i] = copy._tab[i];
	}
	else if (this->_size == 0)
		this->_tab = NULL;
	return (*this);	
};
template <typename T, class Alloc>
vector<T, Alloc>::~vector(){
	return ;
};

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator					vector<T, Alloc>::begin(){
	return (iterator(this->_tab));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::begin() const{
	return (const_iterator(this->_tab));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator 				vector<T, Alloc>::end(){
	return (iterator(this->_tab + this->_size));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::end() const{
	return (const_iterator(this->_tab + this->_size));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reverse_iterator 		vector<T, Alloc>::rbegin(){
	return (reverse_iterator(this->_tab + this->_size));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rbegin() const{
	return (const_reverse_iterator(this->_tab + this->_size));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reverse_iterator		vector<T, Alloc>::rend(){
	return (reverse_iterator(this->_tab))
};

template <typename T, class Alloc>
// const_reverse_iterator	rend() const ;
// size_type	size() const;
// size_type	max_size() const;
// void		resize (size_type n, value_type val = value_type());
// size_type	capacity() const;
// bool 		empty() const;
// void 		reserve (size_type n);
// reference 			operator[] (size_type n);
// const_reference 	operator[] (size_type n) const;
// reference 			at (size_type n);
// const_reference 	at (size_type n) const;
// reference 			front();
// const_reference 	front() const;
// reference			back();
// const_reference 	back() const;
// value_type*			data();
// const value_type*	data() const;
// template <class InputIterator>
// void 		assign (InputIterator first, InputIterator last);
// void		assign (size_type n, const value_type& val);
// void		push_back (const value_type& val);
// void		pop_back();
// iterator	insert(iterator position, const value_type& val);
// void		insert (iterator position, size_type n, const value_type& val);
// template <class InputIterator>
// void		insert (iterator position, InputIterator first, InputIterator last);
// iterator	erase (iterator position);
// iterator	erase (iterator first, iterator last);
// void		swap (vector& x);
// void		clear();
// allocator_type get_allocator() const;

#endif