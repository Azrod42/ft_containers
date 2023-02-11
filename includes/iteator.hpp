#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template <class T> 
	struct random_access_iterator_tag 
	{
			typedef T				value_type;
			typedef T*				pointer;
			typedef T&				reference;
			typedef std::ptrdiff_t	difference_type;
			
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
			value_type					&operator*();
			value_type					*operator->();
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

// 	template <class T> 
// 	class Riteratorv : public Iteratorv<T>
// 	{
// 		public:
// 			typedef T	value_type;
// 			typedef T*	pointer;
// 			typedef T&	reference;
// 		public:
// 			Riteratorv(){};
// 			~Riteratorv(){};
// 			Riteratorv(pointer ptr) {
// 				this->_ptr = ptr;
// 			};
// 			Riteratorv(const Riteratorv &rhs){ *this = rhs; };
// 			Riteratorv 	&operator=(const Riteratorv &rhs) {
// 				this->_ptr = rhs._ptr;
// 				return (*this);
// 			};
// 			bool		operator==(const Riteratorv &rhs){
// 				return (this->_ptr == rhs._ptr);
// 			};
// 			bool		operator!=(const Riteratorv &rhs){
// 				return (this->_ptr != rhs._ptr);
// 			};
// 			value_type	&operator*() {
// 				return (*this->_ptr);
// 			};
// 			value_type	*operator->() {
// 				return (this->_ptr);
// 			};
// 			Riteratorv	&operator++(){
// 				this->_ptr--;
// 				return (*this);
// 			};
// 			Riteratorv	&operator--(){
// 				this->_ptr++;
// 				return (*this);
// 			};
// 			Riteratorv	operator++(int){
// 				Riteratorv temp(*this);
// 				this->_ptr--;
// 				return (temp);
// 			};
// 			Riteratorv	operator--(int){
// 				Riteratorv temp(*this);
// 				this->_ptr++;
// 				return (temp);
// 			};
// 			Riteratorv	operator+(size_t i) {
// 				Riteratorv	temp(*this);
// 				temp._ptr += i;
// 				return (temp);
// 			};
// 			Riteratorv	operator-(size_t i) {
// 				Riteratorv	temp(*this);
// 				temp._ptr -= i;
// 				return (temp);
// 			};
// 			bool		operator<(const Riteratorv &rhs){
// 				return (this->_ptr < rhs);
// 			};
// 			bool		operator<=(const Riteratorv &rhs){
// 				return (this->_ptr <= rhs);
// 			};
// 			bool		operator>(const Riteratorv &rhs){
// 				return (this->_ptr > rhs);
// 			};
// 			bool		operator>=(const Riteratorv &rhs){
// 				return (this->_ptr >= rhs);
// 			};
// 			Riteratorv	&operator+=(size_t i){
// 				this->_ptr += i;
// 				return (*this);
// 			};
// 			Riteratorv	&operator-=(size_t i){
// 				this->_ptr -= i;
// 				return (*this);
// 			};
// 			value_type	&operator[](size_t i){
// 				return (*this->_ptr[i]);
// 			};
// 	};
// 	template <class T> 
// 	class Citeratorv : public Iteratorv<T>
// 	{
// 		public:
// 			typedef T	value_type;
// 			typedef T*	pointer;
// 			typedef T&	reference;
// 		public:
// 			Citeratorv(){};
// 			~Citeratorv(){};
// 			Citeratorv(pointer ptr) {
// 				this->_ptr = ptr;
// 			};
// 			Citeratorv(const Citeratorv &rhs){ *this = rhs; };
// 			Citeratorv 	&operator=(const Citeratorv &rhs) {
// 				this->_ptr = rhs._ptr;
// 				return (*this);
// 			};
// 			value_type	&operator*() {
// 				return (*this->_ptr);
// 			};
// 			value_type	*operator->() {
// 				return (this->_ptr);
// 			};
// 			const value_type	&operator[](size_t i){
// 				return (*this->_ptr[i]);
// 			};
// 	};
// 	template <class T> 
// 	class CRiteratorv : public Iteratorv<T>
// 	{
// 		public:
// 			typedef T	value_type;
// 			typedef T*	pointer;
// 			typedef T&	reference;
// 		public:
// 			CRiteratorv(){};
// 			~CRiteratorv(){};
// 			CRiteratorv(pointer ptr) {
// 				this->_ptr = ptr;
// 			};
// 			CRiteratorv(const CRiteratorv &rhs){ *this = rhs; };
// 			CRiteratorv 	&operator=(const CRiteratorv &rhs) {
// 				this->_ptr = rhs._ptr;
// 				return (*this);
// 			};
// 			value_type	&operator*() {
// 				return (*this->_ptr);
// 			};
// 			value_type	*operator->() {
// 				return (this->_ptr);
// 			};
// 			const value_type	&operator[](size_t i){
// 				return (*this->_ptr[i]);
// 			};
// 	};
// }
// #endif