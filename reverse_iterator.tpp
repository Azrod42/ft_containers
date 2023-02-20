#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP

#include"reverse_iterator.hpp"
using namespace ft;
			
template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator()
: _rit(0){
	return ;
};
template <class Iterator>
reverse_iterator<Iterator>::~reverse_iterator(){
	return ;
};

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator (iterator_type it)
{
	this->_rit = it - 1;
};

template <class Iterator>
template <class Iter> 
reverse_iterator<Iterator>::reverse_iterator (const reverse_iterator<Iter>& rev_it){
	this->_rit = rev_it.base() - 1;
};

// template <class Iterator>
// template <class Iter> 
// reverse_iterator<Iterator>&		reverse_iterator<Iterator>::operator=(const reverse_iterator<Iter>& rev_it){
	// this->_rit = rev_it->_rit;
	// return (*this);
// };

template <class Iterator>
typename reverse_iterator<Iterator>::iterator_type 		reverse_iterator<Iterator>::base() const{
	return (this->_rit + 1);
};

template <class Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const{
	iterator_type temp = this->base() - 1;
	return (*temp);
};

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+ (difference_type n) const{
	reverse_iterator<Iterator> temp(this->base() + n);
	return (temp);	
};

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++(){
	this->_rit--;
	return (*this);
};

template <class Iterator>
reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator++(int){
	reverse_iterator<Iterator> tmp = *this;
	++(*this);
	return (tmp);
};

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+= (difference_type n){
	this->_rit -= n;
	return (*this);
};

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator- (typename reverse_iterator<Iterator>::difference_type n) const{
	reverse_iterator<Iterator> temp(this->base() + n);
	return (temp);	
};

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--(){
	this->_rit++;
	return (*this);
};

template <class Iterator>
reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator--(int){
	reverse_iterator<Iterator> tmp = *this;
	this->_rit++;
	return (tmp);
};

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-= (difference_type n){
	this->_rit += n;
	return (*this);
};

template <class Iterator>
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const{
	return (this->_rit);
};

template <class Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[] (difference_type n) const {
	// this->_rit = this->base() - n;
	return (this->base()[-n - 1]);
};

template <class Iterator, class Iterator2>
bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs){
	return (lhs.base() != rhs.base());
};
template <class Iterator, class Iterator2>
bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs){
	return (lhs._rit < rhs._rit);
};
template <class Iterator, class Iterator2>
bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs){
	return (lhs._rit <= rhs._rit);
};
template <class Iterator, class Iterator2>
bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs){
	return (lhs._rit > rhs._rit);
};
template <class Iterator, class Iterator2>
bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs){
	return (lhs._rit >= rhs._rit);
};

#endif