#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_base.hpp"
#include "iterator_traits.hpp"

namespace ft {

template<class RanIt>
class reverse_iterator: public ft::iterator<
	typename ft::iterator_traits<RanIt>::iterator_category,
	typename ft::iterator_traits<RanIt>::value_type,
	typename ft::iterator_traits<RanIt>::difference_type,
	typename ft::iterator_traits<RanIt>::pointer,
	typename ft::iterator_traits<RanIt>::reference>
{
	public:
		typedef typename ft::iterator_traits<RanIt>::difference_type	difference_type;
		typedef typename ft::iterator_traits<RanIt>::pointer			pointer;
		typedef typename ft::iterator_traits<RanIt>::reference			reference;

		reverse_iterator() {}

		reverse_iterator(RanIt iterator): current(iterator) {}

		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter>& other): current(other.base()) {}

		RanIt base() const {
			return current;
		}

		reference operator*() const {
			RanIt temp = current;
			return *(--temp);
		}

		reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(current - n);
		}

		reverse_iterator &operator++() {
			current--;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator temp = *this;
			current--;
			return temp;
		}

		reverse_iterator& operator+=(difference_type n) {
			current -= n;
			return *this;
		}

		reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(current + n);
		}

		reverse_iterator& operator--() {
			current++;
			return *this;
		}

		reverse_iterator  operator--(int) {
			reverse_iterator temp = *this;
			current++;
			return temp;
		}

		reverse_iterator& operator-=(difference_type n) {
			current += n;
			return *this;
		}

		pointer operator->() const {
			return &**this;
		}

		reference operator[](difference_type n) const {
			return *(*this + n);
		}

	protected:
		RanIt current;
};


template <class Iterator1, class Iterator2>
bool operator== (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator!= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator< (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator> (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() <= rhs.base();
}

}

#endif //REVERSE_ITERATOR_HPP
