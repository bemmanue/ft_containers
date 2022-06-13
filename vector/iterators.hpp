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
	return iterator(_last);
};

template <typename T, class Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const {
	return const_iterator(_last);
};

template <typename T, class Alloc>
typename vector<T, Alloc>::reverse_iterator	vector<T, Alloc>::rbegin() {
	return reverse_iterator(end());
}

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const {
	return const_reverse_iterator(end());
}

template <typename T, class Alloc>
typename vector<T, Alloc>::reverse_iterator	vector<T, Alloc>::rend() {
	return reverse_iterator(begin());
}

template <typename T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const {
	return const_reverse_iterator(begin());
}

}

#endif
