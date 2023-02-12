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
:	_rit(it - 1){
};

template <class Iterator>
template <class Iter> 
reverse_iterator<Iterator>::reverse_iterator (const reverse_iterator<Iter>& rev_it){
	*this = rev_it;
};

template <class Iterator>
template <class Iter> 
reverse_iterator<Iterator>&		reverse_iterator<Iterator>::operator=(const reverse_iterator<Iter>& rev_it){
	this->_rit = rev_it->_rit;
	return (*this);
};
// iterator_type base() const;
// reference operator*() const;
// reverse_iterator operator+ (difference_type n) const;
// reverse_iterator& operator++();
// reverse_iterator  operator++(int);
// reverse_iterator& operator+= (difference_type n);
// reverse_iterator operator- (difference_type n) const;
// reverse_iterator& operator--();
// reverse_iterator  operator--(int);
// reverse_iterator& operator-= (difference_type n);
// pointer operator->() const;
// reference operator[] (difference_type n) const;
// template <class Iterator>
// bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
// template <class Iterator>
// bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
// template <class Iterator>
// bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
// template <class Iterator>
// bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
// template <class Iterator>
// bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
// template <class Iterator>
// bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
// template <class Iterator>
// reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);
// template <class Iterator>
// typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

#endif