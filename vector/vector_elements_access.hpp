#ifndef VECTOR_ELEMENTS_ACCESS_HPP
#define VECTOR_ELEMENTS_ACCESS_HPP

#include "vector_base.hpp"

namespace ft {

template <typename T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n) {
	return (*(begin() + n));
}

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const {
	return (*(begin() + n));
}

template <typename T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n) {
	if (n >= _last - _first)
		throw std::out_of_range("vector");
	return (*(begin() + n));
}

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
	if (n >= _last - _first)
		throw std::out_of_range("vector");
	return (*(begin() + n));
}

template <typename T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front() {
	return *(begin());
}

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const {
	return *(begin());
}

template <typename T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back() {
	return *(end() - 1);
}

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const {
	return *(end() - 1);
}

}

#endif //VECTOR_ELEMENTS_ACCESS_HPP
