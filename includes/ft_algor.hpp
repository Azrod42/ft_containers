#ifndef FT_ALGO_HPP
# define FT_ALGO_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <stdexcept>
// # include <cmaths>
# include <memory>
# include <algorithm>
# include <cstddef>

namespace ft
{
	template <class T1, class T2> 
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	f;
		second_type	s;
		pair(): f(), s() {};

		template<class U, class V> 
		pair (const pair<U,V>& pr) : f(pr.f), s(pr.s){};
		pair (const first_type& a, const second_type& b) : f(a), s(b){};

		pair& operator= (const pair& pr){
			f = pr.f;
			s = pr.s;
			return (*this);
		};
	};
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs.f == rhs.f && lhs.s == lhs.s ? true : false);
	};
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs == rhs ? false : true);
	};
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return ((lhs.f < rhs.f || (!(lhs.f < rhs.f) && lhs.s < rhs.s)) ? true : false);
	};
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (rhs < lhs ? false : true);
	};
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (rhs < lhs ? true : false);
	};
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs < rhs ? false : true);
	};
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y){
		return(pair<T1,T2>(x, y));
	};
	template <class T, bool v>
	struct integral_constant {
		static const bool value = v;
		typedef T							value_type;
		typedef integral_constant<T,v>	type;
		operator T() { return value; }
	};
	template <class T> struct is_integral : public ft::integral_constant<T, false> {};
	template <> struct is_integral<bool> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char16_t> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char32_t> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<signed char> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<short int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<long int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<long long int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned short int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long int> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long long int> : public ft::integral_constant<bool, true> {};
	typedef integral_constant<bool,true> true_type;

	template <bool Cond, class T, class F>
	struct conditional {
		typedef F type;
	};
	template <class T, class F>
	struct conditional<true, T, F> {
		typedef T type;
	};
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
};
#endif