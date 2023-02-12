#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include"iteator.hpp"

namespace	ft {
	template <classe Iterator>
	class iterator_traits {
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	}
	template <class T>
	class iterator_traits<T*> {
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	}
}

#endif