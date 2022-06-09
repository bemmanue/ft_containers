#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "vector.hpp"

namespace ft
{

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin() {
	return iterator(_first);
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const {
	return const_iterator(_first);
};

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end() {
	return iterator(_last - 1);
};



}

#endif
