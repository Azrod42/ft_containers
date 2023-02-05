#ifndef ITERATORV_HPP
# define ITERATORV_HPP

namespace ft
{
	template <class T> 
	class Iteratorv 
	{
		public:
			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;
			
		private:
			pointer _ptr;
			
		public:
			Iteratorv(){};
			~Iteratorv(){};
			Iteratorv(pointer ptr) : _ptr(ptr){};
			Iteratorv(const Iteratorv &rhs){ *this = rhs; };
			Iteratorv 	&operator=(const Iteratorv &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			};
			bool		operator==(const Iteratorv &rhs){
				return (this->_ptr == rhs);
			};
			bool		operator!=(const Iteratorv &rhs){
				return (this->_ptr == rhs);
			};
			Iteratorv	operator*() {
				return (this->_ptr);
			}
			Iteratorv	operator++(){
				this->_ptr++;
				return (this->_ptr);
			};
			Iteratorv	operator--(){
				this->_ptr--;
				return (this->_ptr);
			};
			Iteratorv	operator++(int){
				Iteratorv temp(*this);
				this->_ptr++;
				return (temp);
			};
			Iteratorv	operator--(int){
				Iteratorv temp(*this);
				this->_ptr++;
				return (temp);
			};
			Iteratorv	operator+(size_t i) {
				Iteratorv	temp(*this);
				temp._ptr += i;
				return (temp);
			};
			Iteratorv	operator-(size_t i) {
				Iteratorv	temp(*this);
				temp._ptr -= i;
				return (temp);
			};
			bool		operator<(const Iteratorv &rhs){
				return (this->_ptr < rhs);
			};
			bool		operator<=(const Iteratorv &rhs){
				return (this->_ptr <= rhs);
			};
			bool		operator>(const Iteratorv &rhs){
				return (this->_ptr > rhs);
			};
			bool		operator>=(const Iteratorv &rhs){
				return (this->_ptr >= rhs);
			};



	};
}
#endif