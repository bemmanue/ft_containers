#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft {

template<class Iterator>
class reverse_iterator: public iterator<
	typename ft::iterator_traits<Iterator>::iterator_category,
	typename ft::iterator_traits<Iterator>::value_type,
	typename ft::iterator_traits<Iterator>::difference_type,
	typename ft::iterator_traits<Iterator>::pointer,
	typename ft::iterator_traits<Iterator>::reference>
{
public:
	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
	typedef typename ft::iterator_traits<Iterator>::reference			reference;

	reverse_iterator() {}


	explicit reverse_iterator(Iterator iterator): current(iterator) {}


	template<class Iter>
	reverse_iterator(const reverse_iterator<Iter>& other): current(other.base()) {}


	template<class Iter>
	reverse_iterator& operator=(const reverse_iterator<Iter>& other) {
		current = other.base();
	}

	Iterator base() const {
		return current;
	}

	reference operator*() const {
		Iterator temp = current;
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

	reverse_iterator& operator+= (difference_type n) {
		current -= n;
		return *this;
	}

	reverse_iterator operator- (difference_type n) const {
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

	reverse_iterator& operator-= (difference_type n) {
		current += n;
		return *this;
	}

	pointer operator->() const {
		return std::addressof(operator*());
	}

	reference operator[] (difference_type n) const {
		return *(*this + n);
	}

protected:
	Iterator current;
};

template <class Iterator1, class Iterator2>
bool operator== (const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator!= (const reverse_iterator<Iterator1>& lhs,
				 const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator< (const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<= (const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator> (const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>= (const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() <= rhs.base();
}

}

#endif
