#ifndef VECTOR_HPP
# define VECTOR_HPP

# include<iostream>
# include<cmath>
# include<cstdio>
# include"ft_include.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;	
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef ft::random_access_iterator_tag<T> 				iterator;
			typedef ft::random_access_iterator_tag<const T> 		const_iterator;
			typedef ft::reverse_iterator<T> 						reverse_iterator;
			typedef ft::reverse_iterator<const T> 					const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef size_t											size_type;

		private:
			pointer			_vector;
			size_type		_size;
			size_type		_size_fill;
			allocator_type	_alloc;

		public:
			///////////////////////////////////////
			//			Iterators:               //
			///////////////////////////////////////
			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); 
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x);
			vector &operator=(const vector &copy);
			~vector();
			///////////////////////////////////////
			//			Iterators:               //
			///////////////////////////////////////
			iterator				begin();
			const_iterator			begin() const;
			iterator 				end();
			const_iterator			end() const;
			reverse_iterator 		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const ;
			///////////////////////////////////////
			//			Capacity:               //
			///////////////////////////////////////
			size_type	size() const;
			size_type	max_size() const;
			void		resize (size_type n, value_type val = value_type());
			size_type	capacity() const;
			bool 		empty() const;
			void 		reserve (size_type n);
			///////////////////////////////////////
			//			Element access:          //
			///////////////////////////////////////
			reference 			operator[] (size_type n);
			const_reference 	operator[] (size_type n) const;
			reference 			at (size_type n);
			const_reference 	at (size_type n) const;
			reference 			front();
			const_reference 	front() const;
			reference			back();
			const_reference 	back() const;
			value_type*			data();
			const value_type*	data() const;
			///////////////////////////////////////
			//			  Modifiers:             //
			///////////////////////////////////////
			template <class InputIterator>
			void 		assign (InputIterator first, InputIterator last);
			void		assign (size_type n, const value_type& val);
			void		push_back (const value_type& val);
			void		pop_back();
			iterator	insert(iterator position, const value_type& val);
			void		insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void		insert (iterator position, InputIterator first, InputIterator last);
			iterator	erase (iterator position);
			iterator	erase (iterator first, iterator last);
			void		swap (vector& x);
			void		clear();
			///////////////////////////////////////
			//			  Allocator:             //
			///////////////////////////////////////
			allocator_type get_allocator() const;
	};
}
#endif