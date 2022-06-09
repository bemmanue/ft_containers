#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "iterator_tags.hpp"

namespace ft
{

template<class T, class D, class P, class R, class P2, class R2>
class random_access_iterator : iterator<random_access_iterator_tag, T, D, P2, R2>
{
public:
	typedef random_access_iterator<T, D, P, R, P2, R2>	iterator;
	typedef typename iterator::iterator_category 		iterator_category;
	typedef typename iterator::value_type 				value_type;
	typedef typename iterator::difference_type 			difference_type;
	typedef typename iterator::pointer 					pointer;
	typedef typename iterator::reference 				reference;


	random_access_iterator() {

	}

	random_access_iterator(const random_access_iterator<T, D, P, R, P2, R2>& iterator): current(iterator.base()) {

	}


	template <class _T, class _D, class _P, class _R, class _P2, class _R2>
	random_access_iterator(const random_access_iterator<_T, _D, _P, _R, _P2, _R2>& iterator): current(iterator.base()) {

	}

	pointer base() const {
		return (current);
	}

	explicit random_access_iterator(P2 pointer): current(pointer) {

	}

	R operator*	() const {
		return *current;
	}

	random_access_iterator& operator= (const iterator& a) {
		current = a.current;
		return *this;
	}

	random_access_iterator& operator+= (difference_type n) {
		current += n;
		return *this;
	}

	iterator& operator++ () {
		current++;
		return *this;
	}

	iterator operator++ (int) {
		iterator temp = *this;
		current++;
		return temp;
	}

	iterator operator+ (difference_type n) {
		iterator temp = *this;
		return (temp += n);
	}

	iterator& operator-= (difference_type n) {
		current -= n;
		return *this;
	}

	iterator operator- (difference_type n) {
		iterator temp = *this;
		return (temp -= n);
	}

	difference_type operator- (const iterator& a) {
		return (current - a.current);
	}

	reference operator[] (D n) const {
		return *(current + n);
	}

	bool operator< (const iterator& b) const {
		return (current < b.current);
	}

	bool operator> (const iterator& b) const {
		return (current > b.current);
	}

	bool operator<= (const iterator& b) const {
		return (current <= b.current);
	}

	bool operator>= (const iterator& b) const {
		return (current >= b.current);
	}

	bool operator== (const iterator& b) const {
		return (current == b.current);
	}

	bool operator!= (const iterator& b) const {
		return (current != b.current);
	}
protected:
	pointer	current;
};

}

#endif
