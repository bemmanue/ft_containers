#ifndef ITERATOR_CATEGORY_HPP
#define ITERATOR_CATEGORY_HPP

#include "iterator_tags.hpp"
#include "iterator_base.hpp"

namespace ft {

template <class C, class T, class Dist, class Pt, class Rt> inline
C Iter_cat(const iterator<C, T, Dist, Pt, Rt>&) {
	C x;
	return x;
}

template<class T> inline
random_access_iterator_tag Iter_cat(const T*) {
	ft::random_access_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(bool) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(char) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(signed char) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(unsigned char) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(wchar_t) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(short) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(unsigned short) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(int) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(unsigned int) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(long) {
	int_iterator_tag x;
	return x;
}

inline int_iterator_tag Iter_cat(unsigned long) {
	int_iterator_tag x;
	return x;
}

}

#endif //ITERATOR_CATEGORY_HPP
