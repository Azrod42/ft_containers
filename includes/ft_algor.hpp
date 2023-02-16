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
		return ((lsh.f < rhs.f || (!(lsh.f < rhs.f) && lsh.s < rhs.s)) ? true : false)
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
};
#endif