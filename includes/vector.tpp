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
		throw InvalidArgument();
}; 

template <typename T, class Alloc>
template <class InputIterator>
vector<T, Alloc>::vector (InputIterator first, InputIterator last, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
: _size(0), _size_fill(0), _tab(NULL), _alloc(alloc){
	difference_type toconv = last - first;
	size_type n = (size_type)toconv;	

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
	this->_size = copy._size;
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
	return (typename vector<T, Alloc>::iterator(this->_tab));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::begin() const{
	return (typename vector<T, Alloc>::const_iterator(this->_tab));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator 				vector<T, Alloc>::end(){
	return (typename vector<T, Alloc>::iterator(this->_tab + this->_size));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::end() const{
	return (typename vector<T, Alloc>::const_iterator(this->_tab + this->_size));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reverse_iterator 		vector<T, Alloc>::rbegin(){
	return (typename vector<T, Alloc>::reverse_iterator(this->_tab + this->_size));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rbegin() const{
	return (typename vector<T, Alloc>::const_reverse_iterator(this->_tab + this->_size));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reverse_iterator		vector<T, Alloc>::rend(){
	return (typename vector<T, Alloc>::reverse_iterator(this->_tab));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rend() const {
	return (typename vector<T, Alloc>::const_reverse_iterator(this->_tab));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::size() const{
	return (this->_size);
};

template <typename T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::max_size() const{
	return (std::numeric_limits<size_type>::max() / sizeof(value_type));
};

template <typename T, class Alloc>
void	vector<T, Alloc>::resize (size_type n, value_type val){
	if (n < 0)
		throw InvalidArgument();
	T	*dup = new T[this->_size];
	for (size_type i = 0; i < this->_size; i++)
		dup[i] = this->_tab[i];
	if (n < this->_size)
	{
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_tab + i);
		this->_alloc.deallocate(this->_tab, this->_size);
		this->_size = n;
		this->_size_fill = n;
		this->_tab = this->_alloc.allocate(this->_size);
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.construct(this->_tab + i, dup[i]);
	}
	else if (n > this->_size)
	{
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_tab + i);
		this->_alloc.deallocate(this->_tab, this->_size);
		this->_tab = this->_alloc.allocate(n);
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.construct(this->_tab + i, dup[i]);
		size_type old = this->_size;
		this->_size = n;
		this->_size_fill = n;
		for(size_type i = old + 1; i < this->_size; i++)
			this->_alloc.construct(this->_tab + i, val);
	}
	delete[] dup;
};

template <typename T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity() const{
	return (this->_size_fill);
};

template <typename T, class Alloc>
bool 		vector<T, Alloc>::empty() const {
	return (this->_size == 0);
};

template <typename T, class Alloc>
void 		vector<T, Alloc>::reserve (size_type n){
	if (n < 0)
		throw InvalidArgument();
	if (n > this->_size_fill)
	{
		T	*dup = new T[this->_size];
		for (size_type i = 0; i < this->_size; i++)
			dup[i] = this->_tab[i];
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_tab + i);
		this->_alloc.deallocate(this->_tab, this->_size);
		this->_size_fill = n;
		this->_tab = this->_alloc.allocate(this->_size_fill);
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.construct(this->_tab + i, dup[i]);	
		delete[] dup;
	}
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reference 			vector<T, Alloc>::operator[] (size_type n){
	return (*(this->_tab + n));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference 	vector<T, Alloc>::operator[] (size_type n) const{
	return (*(this->_tab + n));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reference 			vector<T, Alloc>::at (size_type n){
	if (n < 0 || n >= this->_size)
		throw OutOfRange();
	return (*(this->_tab + n));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference 	vector<T, Alloc>::at (size_type n) const{
	if (n < 0 || n >= this->_size)
		throw OutOfRange();
	return (*(this->_tab + n));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reference 			vector<T, Alloc>::front(){
	return (*this->_tab);
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference		vector<T, Alloc>::front() const{
	return (*this->_tab);
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reference			vector<T, Alloc>::back(){
	return (*(this->_tab + this->_size - 1));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference 	vector<T, Alloc>::back() const{
	return (*(this->_tab + this->_size - 1));
};

template <typename T, class Alloc>
typename vector<T, Alloc>::value_type*			vector<T, Alloc>::data(){
	return (this->_tab);
};

template <typename T, class Alloc>
const typename  vector<T, Alloc>::value_type*	vector<T, Alloc>::data() const{
	return (this->_tab);
};

template <typename T, class Alloc>
void		 vector<T, Alloc>::assign (size_type n, const value_type& val){
	for(size_type i = 0; i < this->_size; i++)
		this->_alloc.destroy(this->_tab + i);
	this->_alloc.deallocate(this->_tab, this->_size);
		this->_size = n;
	if (this->_size_fill < this->_size)
		this->_size_fill = this->_size;
		this->_tab = this->_alloc.allocate(this->_size_fill);
	for(size_type i = 0; i < this->_size; i++)
		this->_alloc.construct(this->_tab + i, val);
};

template <typename T, class Alloc>
template <class InputIterator>
void 		 vector<T, Alloc>::assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*) {
	difference_type toconv = last - first;
	size_type n = (size_type)toconv;

	T	*dup = new T[n];
	for (size_type i = 0; i < n; i++)
		dup[i] = *(first + i);	
	this->_size = n;
	if (this->_size_fill < this->_size)
		this->_size_fill = this->_size;
		this->_tab = this->_alloc.allocate(this->_size_fill);
	for(size_type i = 0; i < this->_size; i++)
		this->_alloc.construct(this->_tab + i, dup[i]);
	delete[] dup;
};

template <typename T, class Alloc>
void		vector<T, Alloc>::push_back (const value_type& val){
	if (this->_size_fill == 0){
		this->_tab = this->_alloc.allocate(1);
		this->_size_fill = 1;
		this->_size = 1;
		this->_alloc.construct(this->_tab, val);
		return ;
	}
	if (this->_size == this->_size_fill)
		reserve(this->_size + 1);
	if (this->_size < this->_size_fill)
	{
		this->_alloc.construct(this->_tab + this->_size, val);
		this->_size += 1;
	}
};

template <typename T, class Alloc>
void		vector<T, Alloc>::pop_back(){
	this->_alloc.destroy(this->_tab + --this->_size);
};

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator position, const value_type& val){
	size_type		size = this->_size;
	difference_type pos = position - this->begin();
	
	T	*dup = new T[this->_size];
	for (size_type i = 0; i < this->_size; ++i)
		dup[i] = this->_tab[i];	
	for (size_type i = 0; i < size; ++i)
		this->pop_back();
	for (size_type i = 0; i < (size_t)pos; ++i)
		this->push_back(dup[i]);
	this->push_back(val);
	for (size_type i = (size_type)pos; i < size; ++i)
		this->push_back(dup[i]);
	delete[] dup;
	return (this->begin() + pos);
};

template <typename T, class Alloc>
void vector<T, Alloc>::insert (typename vector<T, Alloc>::iterator position,size_t n,typename  vector<T, Alloc>::value_type const &val){
	std::cout << this->_size_fill << " " << this->_size << std::endl;
	size_type 		size = this->_size;
	difference_type pos = position - this->begin(); 
	
	T	*dup = new T[this->_size];
	for (size_type i = 0; i < this->_size; ++i)
		dup[i] = this->_tab[i];	
	for (size_type i = 0; i < size; ++i)
		this->pop_back();
	for (size_type i = 0; i < (size_t)pos; ++i)
		this->push_back(dup[i]);
	for (size_type i = 0; i < n ; ++i)
		this->push_back(val);
	for (size_type i = (size_type)pos; i < size; ++i)
		this->push_back(dup[i]);
	delete[] dup;
};


template <typename T, class Alloc>
template <class InputIterator>
void		vector<T, Alloc>::insert (vector<T, Alloc>::iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*){//, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*){
	size_type 		size = this->_size;
	difference_type pos = position - this->begin();
	difference_type	size_to_copy = last - first; 
	
	T	*dup = new T[this->_size];
	for (size_type i = 0; i < this->_size; ++i)
		dup[i] = this->_tab[i];	
	for (size_type i = 0; i < size; ++i)
		this->pop_back();
	for (size_type i = 0; i < (size_t)pos; ++i)
		this->push_back(dup[i]);
	for (size_type i = 0; i < (size_t)size_to_copy ; ++i)
		this->push_back(*(first + i));
	for (size_type i = (size_type)pos; i < size; ++i)
		this->push_back(dup[i]);
	delete[] dup;
	return ;
};

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase (vector<T, Alloc>::iterator position){
	size_type 		size = this->_size;
	difference_type pos = position - this->begin();
	
	T	*dup = new T[this->_size];
	for (size_type i = 0; i < this->_size; ++i)
		dup[i] = this->_tab[i];	
	for (size_type i = 0; i < size; ++i)
		this->pop_back();
	for (size_type i = 0; i < (size_t)pos; ++i)
		this->push_back(dup[i]);
	for (size_type i = (size_type)pos + 1; i < size; ++i)
		this->push_back(dup[i]);
	delete[] dup;
	return(this->begin() + pos);

};

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase (vector<T, Alloc>::iterator first, vector<T, Alloc>::iterator last){;
	size_type 		size = this->_size;
	difference_type pos = first - this->begin();
	difference_type	size_to_copy = last - first; 
	
	T	*dup = new T[this->_size];
	for (size_type i = 0; i < this->_size; ++i)
		dup[i] = this->_tab[i];	
	for (size_type i = 0; i < size; ++i)
		this->pop_back();
	for (size_type i = 0; i < (size_t)pos; ++i)
		this->push_back(dup[i]);
	for (size_type i = (size_type)pos + (size_t)size_to_copy; i < size; ++i)
		this->push_back(dup[i]);
	delete[] dup;
	return(this->begin() + pos);
}

template <typename T, class Alloc>
void		vector<T, Alloc>::swap (vector& x){
	if (x == *this)
		return ;
	
	pointer			six = this->_size;
	pointer			sfx = this->_size_fill;
	pointer			tax = this->_tab;
	allocator_type	alx = this->_alloc;

	x._alloc = this->_alloc;
	x._size = this->_size;
	x._size_fill = this->_size_fill;
	x._tab = this->_tab;
	this->_size = six;
	this->_size_fill = sfx;
	this->_tab = tax;
	this->_alloc = alx;
};

template <typename T, class Alloc>
void		vector<T, Alloc>::clear(){
	if (this->_size){
		this->_alloc.deallocate(this->_vector, this->_size);
		this->_vector = this->_alloc.allocate(0);
		this->_size = 0;
	}
};

template <typename T, class Alloc>
typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const{
	allocator_type ret = this->_alloc;
	return (ret);
};

#endif