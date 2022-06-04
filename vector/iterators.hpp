#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "vector.hpp"

namespace ft
{

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::vector::begin() {
	return iterator(_first);
};



}

#endif
