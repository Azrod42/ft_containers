#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include"ft_include.hpp"

namespace	ft {
	template <class Iterator>
	class reverse_iterator{

			typedef Iterator										iterator_type;
			typedef iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef iterator_traits<Iterator>::value_type			value_type;
			typedef iterator_traits<Iterator>::difference_type		difference_type;
			typedef iterator_traits<Iterator>::pointer				pointer;
			typedef iterator_traits<Iterator>::reference			reference;
			
			pointer ptr;
			
			reverse_iterator();
			~reverse_iterator();
			reverse_iterator(pointer ptrin);
			reverse_iterator(const reverse_iterator<T> &rhs);
	};
}

#endif