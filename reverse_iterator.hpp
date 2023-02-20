#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include"ft_include.hpp"

namespace	ft
{
	template <class Iterator>
	class reverse_iterator{
		public :
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
		
		protected:
			iterator_type _rit;
		
		public:
			reverse_iterator();
			~reverse_iterator();
			explicit reverse_iterator (iterator_type it);
			template <class Iter> 
			reverse_iterator (const reverse_iterator<Iter>& rev_it);
			template <class Iter> 
			reverse_iterator &operator=(const reverse_iterator<Iter> &rhs) { 
				this->_rit = rhs.base(); 
				return (*this);
			}
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
	template <class Iterator, class Iterator2>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs){
		return (lhs.base() == rhs.base());
	};
	template <class Iterator, class Iterator2>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs);
	template <class Iterator, class Iterator2>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs);
	template <class Iterator, class Iterator2>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs);
	template <class Iterator, class Iterator2>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs);
	template <class Iterator, class Iterator2>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs);
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it){
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	};
	template <class Iterator, class Iterator2>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs){
		return (rhs.base() - lhs.base());
	};
}

#include"reverse_iterator.tpp"

#endif