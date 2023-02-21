#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
    template <class Iterator>
    class reverse_iterator {
		public:
			typedef Iterator									iterator_type;
			typedef typename iterator_type::iterator_category	iterator_category;
			typedef typename iterator_type::value_type			value_type;
			typedef typename iterator_type::pointer				pointer;
			typedef typename iterator_type::reference			reference;
			typedef typename iterator_type::difference_type		difference_type;

		protected:
			iterator_type _itr;
		
		public :

			reverse_iterator() : _itr() {
				return ;
			}
			~reverse_iterator() {
				return ;
			}
			reverse_iterator(iterator_type x) : _itr(x) {
				return ;
			}
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &other) : _itr(other.base()) {
				return ;
			}

			iterator_type base() const {
				return _itr;
			}
			template <class Iter>
			reverse_iterator &operator=(const reverse_iterator<Iter> &other) {
				this->_itr = other.base();
				return (*this);
			}
			reference operator*() const {
				iterator_type tmp = _itr;
				return (*--tmp);
			}
			pointer operator->() const {
				return &(operator*());
			}
			reference operator[](difference_type n) const {
				return this->base()[-n - 1];
			}
			reverse_iterator &operator++() {
				--_itr; return *this;
			}
			reverse_iterator &operator--() {
				++_itr; return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this; --_itr;
				return tmp;
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				++_itr;
				return tmp;
			}
			reverse_iterator operator+(difference_type n) const {
				iterator_type tmp(_itr - n);
				return reverse_iterator(tmp);
			}
			reverse_iterator operator-(difference_type n) const {
				iterator_type tmp(_itr + n);
				return reverse_iterator(tmp);
			}
			reverse_iterator &operator+=(difference_type n) {
				_itr -= n;
				return *this;
			}
			reverse_iterator &operator-=(difference_type n) {
				_itr += n;
				return *this;
			}

    };

    template <class It1, class It2>
    bool operator==(const ft::reverse_iterator<It1> &lhs, const ft::reverse_iterator<It2> &rhs) {
		return (lhs.base() == rhs.base());
	};
    template <class It1, class It2>
    bool operator!=(const ft::reverse_iterator<It1> &lhs, const ft::reverse_iterator<It2> &rhs) {
		return (lhs.base() != rhs.base());
	};
    template <class It1, class It2>
    bool operator<(const ft::reverse_iterator<It1> &lhs, const ft::reverse_iterator<It2> &rhs) {
		return (lhs.base() > rhs.base());
	};
    template <class It1, class It2>
    bool operator<=(const ft::reverse_iterator<It1> &lhs, const ft::reverse_iterator<It2> &rhs) {
		return (lhs.base() >= rhs.base());
	};
    template <class It1, class It2>
    bool operator>(const ft::reverse_iterator<It1> &lhs, const ft::reverse_iterator<It2> &rhs) {
		return (lhs.base() < rhs.base());
	};
    template <class It1, class It2>
    bool operator>=(const ft::reverse_iterator<It1> &lhs, const ft::reverse_iterator<It2> &rhs) {
		return (lhs.base() <= rhs.base());
	};
    template <class Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &it) {
		return (reverse_iterator<Iter>(it.base() - n));
	};
	template <class Iterator, class It2>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<It2>& rhs){
		return (rhs.base() - lhs.base());
	};
} 

#endif