#ifndef VECTOR_HPP
# define VECTOR_HPP

# include<iostream>
# include<cmath>
# include<cstdio>
# include"ft_include.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class vector {
			typedef T												value_type;
			typedef Alloc											allocator_type;	
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::random_access_iterator_tag<T> 				iterator;
			typedef ft::random_access_iterator_tag<const T> 		const_iterator;
			typedef ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			size_type		_size;
			size_type		_size_fill;
			value_type		*_tab;
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
			void 		assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = -1);
			void		assign (size_type n, const value_type& val);
			void		push_back (const value_type& val);
			void		pop_back();
			iterator	insert(iterator position, const value_type& val);
			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last);
			void		insert(iterator position, size_type n, value_type const &val);
			iterator	erase (iterator position);
			iterator	erase (iterator first, iterator last);
			void		swap (vector& x);
			void		clear();
			///////////////////////////////////////
			//			  Allocator:             //
			///////////////////////////////////////
			allocator_type get_allocator() const;
			class InvalidArgument : public std::exception {
			public: virtual const char *what() const throw() { return ("Vector::exception : Invalid argument.");}};

			class OutOfRange : public std::exception {
			public: virtual const char *what() const throw() { return ("Vector::exception : Out of range.");}};

	};
	template <typename T, class Alloc>
	void swap(vector<T, Alloc> &one, vector<T, Alloc> &two){
		one.swap(two);
	};

	template <typename T, class Alloc>
	bool	operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator it1 = lhs.begin();
		typename ft::vector<T>::const_iterator it2 = lhs.begin();
		
		while (it1 != lhs.end())
		{
			if(it2 == rhs.end() || *it1 != *it2)
				return (false);
				it1++;
				it2++;
		}
		return (true);
	};

	template <typename T, class Alloc>
	bool	operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		return (lhs == rhs ? false : true);
	};

	template <typename T, class Alloc>
	bool	operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		
	};
	template <class InputIterator1, class InputIterator2, class Comp>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,InputIterator2 first2, InputIterator2 last2, Comp comp)
	{
		while ((first1 != last1) && (first2 != last2)) {
			if (comp(*first1, *first2)) return (true);
			if (com(*first2, *first1)) return (false);
			first1++
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	}
}

#include"vector.tpp"

#endif