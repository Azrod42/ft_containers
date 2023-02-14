#ifndef ITERATOR_HPP
# define ITERATOR_HPP

// # include"ft_include.hpp"

namespace ft
{
	template <class T> 
	struct random_access_iterator_tag 
	{
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ptrdiff_t					difference_type;
			typedef std::random_access_iterator_tag	iterator_category;
			
			pointer ptr;
			
			random_access_iterator_tag();
			~random_access_iterator_tag();
			random_access_iterator_tag(pointer ptrin);
			random_access_iterator_tag(const random_access_iterator_tag<T> &rhs);

			random_access_iterator_tag 	&operator=(const random_access_iterator_tag &rhs);
			random_access_iterator_tag	&operator++();
			random_access_iterator_tag	&operator--();
			random_access_iterator_tag	operator++(int);
			random_access_iterator_tag	operator--(int);
			value_type					&operator[](unsigned long i);
			reference					operator*();
			pointer						operator->();
	};
		template <typename T>
		bool		operator==(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2);
		template <typename T>
		bool		operator!=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2);
		template <typename T>
		bool		operator<(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2);
		template <typename T>
		bool		operator<=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2);
		template <typename T>
		bool		operator>(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2);
		template <typename T>
		bool		operator>=(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2);
		template <typename T>
		random_access_iterator_tag<T>	operator+=(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n);
		template <typename T>
		random_access_iterator_tag<T>	operator-=(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n);
		template <typename T>
		random_access_iterator_tag<T>	operator+(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n);
		template <typename T>
		random_access_iterator_tag<T>	operator-(const random_access_iterator_tag<T> &it1, typename random_access_iterator_tag<T>::difference_type n);
		template <typename T>
		random_access_iterator_tag<T>	operator+(typename random_access_iterator_tag<T>::difference_type n, const random_access_iterator_tag<T> &it1);
		template <typename T>
		random_access_iterator_tag<T>	operator-(typename random_access_iterator_tag<T>::difference_type n, const random_access_iterator_tag<T> &it1);
		template <typename T>
		typename random_access_iterator_tag<T>::difference_type	operator-(const random_access_iterator_tag<T> &it1, const random_access_iterator_tag<T> &it2);
}

#include"iterator.tpp"

#endif