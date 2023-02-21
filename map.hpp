#ifndef MAP_HPP_
# define MAP_HPP_

# include <iostream>
# include <cstdlib>
# include <string>
# include <stdexcept>
# include <memory>
# include <algorithm>
# include <cstddef>
# include"ft_include.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map {
		public :
		typedef Key							key_type;
		typedef T 							mapped_type;
		typedef ft::pair<const Key, T>		value_type
		typedef std::size_t 				size_type;
		typedef std::ptrdiff_t 				difference_type;
		typedef Compare 					key_compare;
		typedef value_type& 				reference;
		typedef const value_type& 			const_reference;
		typedef Allocator::pointer 			pointer;
		typedef Allocator::const_pointer	const_pointer;
		typedef size_t 						iterator;
		typedef size_t 						const_iterator;
		typedef size_t 						reverse_iterator;
		typedef size_t 						const_reverse_iterator;

		private :

		public :
	};
}
#endif