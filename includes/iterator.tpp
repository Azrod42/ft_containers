#ifndef ITERATOR_TPP
# define ITERATOR_TPP

using namespace ft;

template <class T>
random_access_iterator_tag<T>::random_access_iterator_tag(){
	return ;
}

template <class T>
random_access_iterator_tag<T>::~random_access_iterator_tag(){
	return ;
}

template <class T>
random_access_iterator_tag<T>::random_access_iterator_tag(pointer ptrin) : ptr(ptrin){
	return ;
}

template <class T>
random_access_iterator_tag<T>::random_access_iterator_tag(const random_access_iterator_tag &rhs){
	*this = rhs;
}

template <class T> 
random_access_iterator_tag<T>		&random_access_iterator_tag<T>::operator=(const random_access_iterator_tag<T> &rhs){
	this->ptr = rhs.ptr;
	return (*this);
}

template <class T> 
random_access_iterator_tag<T>		&random_access_iterator_tag<T>::operator++(){
	his->ptr++
	return (*this);
}

template <class T> 
random_access_iterator_tag<T>		&random_access_iterator_tag<T>::operator--(){
	this->ptr--;
	return (*this);
}

template <class T> 
random_access_iterator_tag<T>		random_access_iterator_tag<T>::operator++(int){
	random_access_iterator_tag<T> tmp = *this;
	this->ptr++;
	return (tmp);
}

template <class T> 
random_access_iterator_tag<T>		random_access_iterator_tag<T>::operator--(int){
	random_access_iterator_tag<T> tmp = *this;
	this->ptr--;
	return (tmp);
}

template <class T> 
T									&random_access_iterator_tag<T>::operator[](unsigned long i){
	return (*this->ptr[i]);
}

template <class T> 
T									&random_access_iterator_tag<T>::operator*(){
	return (*this->ptr);
}

template <class T> 
T									*random_access_iterator_tag<T>::operator->(){
	return (this->ptr);
}

template <typename T>
bool								ft::operator==(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2){
	return (it1.ptr == it2.ptr);
}

template <typename T>
bool								ft::operator!=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2){
	return (it1.ptr != it2.ptr);
}

template <typename T>
bool								ft::operator<(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2){
	return (it1.ptr < it2.ptr);
}

template <typename T>
bool								ft::operator<=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2){
	return (it1.ptr <= it2.ptr);
}

template <typename T>
bool								ft::operator>(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2){
	return (it1.ptr > it2.ptr);
}

template <typename T>
bool								ft::operator>=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2){
	return (it1.ptr >= it2.ptr);
}

template <typename T>
random_access_iterator_tag<T>		ft::operator+=(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n){
	typename random_access_iterator_tag<T>::difference_type m = n;
	if (m >= 0){
		while (m--) ++it1.ptr;
	}
	else {
		while (m++) --it1.ptr;
	}
}

template <typename T>
random_access_iterator_tag<T>		ft::operator-=(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n){
	return (it1.ptr += (n *= -1));
}

template <typename T>
random_access_iterator_tag<T>		ft::operator+(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n){
	random_access_iterator_tag<T> tmp = it1;
	return (it1.ptr + n);
}

template <typename T>
random_access_iterator_tag<T>		ft::operator+(typename random_access_iterator_tag<T>::difference_type n, const random_access_iterator_tag<T> &it1){
	random_access_iterator_tag<T> tmp = it1;
	return (it1.ptr + n);
}

template <typename T>
random_access_iterator_tag<T>		ft::operator-(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n){
	random_access_iterator_tag<T> tmp = it1;
	return (it1.ptr - n);
}

template <typename T>
random_access_iterator_tag<T>		ft::operator-(typename random_access_iterator_tag<T>::difference_type n, const random_access_iterator_tag<T> &it1){
	random_access_iterator_tag<T> tmp = it1;
	return (it1.ptr - n);
}

template <typename T>
typename random_access_iterator_tag<T>::difference_type		ft::operator-(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2){
	typename random_access_iterator_tag<T>::difference_type tmp;

	if (it1.ptr > b.ptr)
		tmp = it1.ptr - it2.ptr;
	else
		tmp = it2.ptr - it1.ptr;
	return (tmp);
}
#endif