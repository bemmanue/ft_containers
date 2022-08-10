#ifndef ITERATOR_DISTANCE_HPP
#define ITERATOR_DISTANCE_HPP

#include "iterator_traits.hpp"
#include "iterator_category.hpp"

namespace ft {

template <class InIt> inline
typename ft::iterator_traits<InIt>::difference_type distance(InIt first, InIt last) {
	typename ft::iterator_traits<InIt>::difference_type n = 0;
	Distance2(first, last, n, ft::Iter_cat(first));
	return n;
}

template <class InIt, class Distance> inline
void Distance(InIt first, InIt last, Distance& n) {
	Distance2(first, last, n, ft::Iter_cat(first));
}

template <class InIt, class Distance> inline
void Distance2(InIt first, InIt last, Distance& n, input_iterator_tag) {
	for (; first != last; ++first) {
		++n;
	}
}

template <class InIt, class Distance> inline
void Distance2(InIt first, InIt last, Distance& n, forward_iterator_tag) {
	for (; first != last; ++first) {
		++n;
	}
}

template <class InIt, class Distance> inline
void Distance2(InIt first, InIt last, Distance& n, bidirectional_iterator_tag) {
	for (; first != last; ++first) {
		++n;
	}
}

template <class InIt, class Distance> inline
void Distance2(InIt first, InIt last, Distance& n, random_access_iterator_tag) {
	n += last - first;
}

template <class InIt, class Distance> inline
void Distance_Tree(InIt first, InIt last, Distance& n) {
	for (; first != last; ++first) {
		++n;
	}
}

}

#endif //ITERATOR_DISTANCE_HPP
