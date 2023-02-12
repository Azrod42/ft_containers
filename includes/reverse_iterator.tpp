#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include"ft_include.hpp"

namespace	ft {
			
			reverse_iterator();
			~reverse_iterator();
			explicit reverse_iterator (iterator_type it);
			template <class Iter> 
			reverse_iterator (const reverse_iterator<Iter>& rev_it);

			iterator_type base() const;
			reference operator*() const;
			reverse_iterator operator+ (difference_type n) const;
			reverse_iterator& operator++();
			reverse_iterator  operator++(int);
			reverse_iterator& operator+= (difference_type n);
			reverse_iterator operator- (difference_type n) const;
			reverse_iterator& operator--();
			reverse_iterator  operator--(int);
			reverse_iterator& operator-= (difference_type n);
			pointer operator->() const;
			reference operator[] (difference_type n) const;
	};
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
}

#include"reverse_iterator.tpp"

#endif