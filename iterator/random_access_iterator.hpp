#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "iterator_tags.hpp"

namespace ft
{

template<class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class random_access_iterator : iterator<random_access_iterator_tag, T, Distance, Pointer, Reference>
{
protected:
	Pointer	current;
public:
	typedef random_access_iterator<T, Distance, Pointer, Reference>		iterator;

	random_access_iterator() {

	}

	explicit random_access_iterator(Pointer pointer): current(pointer) {

	}

	T operator*	() const {
		return *current;
	}

	iterator& operator= (const iterator& a) {
		current = a.current;
		return *this;
	}

	iterator& operator+= (Distance n) {
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

	iterator operator+ (Distance n) {
		iterator temp = *this;
		return (temp += n);
	}

	iterator& operator-= (Distance n) {
		current -= n;
		return *this;
	}

	iterator& operator-- () {
		current--;
		return *this;
	}

	iterator operator-- (int) {
		iterator temp = *this;
		current--;
		return temp;
	}

	iterator operator- (Distance n) {
		iterator temp = *this;
		return (temp -= n);
	}

	Distance operator- (const iterator& a) {
		return (current - a.current);
	}

	iterator operator[] (Distance n) const {
		return (current + n);
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
};

}

#endif
