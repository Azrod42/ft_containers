#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include"ft_include.hpp"
# include "Iterator_traits.hpp"

namespace ft
{
	template <class T> 
	struct random_access_iterator_tag 
	{
			typedef typename iterator_traits<T*>::value_type	value_type;
			typedef typename iterator_traits<T*>::pointer	pointer;
			typedef typename iterator_traits<T*>::reference	reference;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;
			
			pointer ptr;
			
			random_access_iterator_tag();
			~random_access_iterator_tag();
			random_access_iterator_tag(pointer ptrin);
			random_access_iterator_tag(const random_access_iterator_tag<typename std::remove_const<T>::type > &rhs);

			random_access_iterator_tag 	&operator=(const random_access_iterator_tag<typename std::remove_const<T>::type>  &rhs);
			random_access_iterator_tag	&operator++();
			random_access_iterator_tag	&operator--();
			random_access_iterator_tag	operator++(int);
			random_access_iterator_tag	operator--(int);
			reference					operator[](unsigned long i);
			reference					operator*();
			pointer						operator->();
	};
		template <typename T, typename U>
		bool		operator==(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<U> &it2);
		template <typename T, typename U>
		bool		operator!=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<U> &it2);
		template <typename T, typename U>
		bool		operator<(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<U> &it2);
		template <typename T, typename U>
		bool		operator<=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<U> &it2);
		template <typename T, typename U>
		bool		operator>(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<U> &it2);
		template <typename T, typename U>
		bool		operator>=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<U> &it2);
		template <typename T>
		random_access_iterator_tag<T>	operator+=( random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n);
		template <typename T>
		random_access_iterator_tag<T>	operator-=( random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n);
		template <typename T>
		random_access_iterator_tag<T>	operator+(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n);
		template <typename T>
		random_access_iterator_tag<T>	operator-(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n);
		template <typename T>
		random_access_iterator_tag<T>	operator+(typename random_access_iterator_tag<T>::difference_type n, const random_access_iterator_tag<T> &it1);
		template <typename T>
		random_access_iterator_tag<T>	operator-(typename random_access_iterator_tag<T>::difference_type n, const random_access_iterator_tag<T> &it1);
		template <typename T, typename U>
		typename random_access_iterator_tag<T>::difference_type	operator-(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<U> &it2);
}

#include"iterator.tpp"

#endif