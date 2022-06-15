#ifndef CONSTRUCTORS_HPP
#define CONSTRUCTORS_HPP

#include "vector.hpp"

namespace ft
{

//	Constructors

template <typename T, class Alloc>
vector<T, Alloc>::vector(const allocator_type&):
	_first(nullptr), _last(nullptr), _end(nullptr) {
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(size_t n, const allocator_type&) {
	if (allocate(n))
		_last = fill(_first, n, T());
}

template <typename T, class Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(InputIterator first, InputIterator last) {
	if (allocate(last - first))
		_last = copy(_first, first, last);
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(const vector& x):
	_first(nullptr), _last(nullptr), _end(nullptr) {
	*this = x;
}

//	Destructor

template <typename T, class Alloc>
vector<T, Alloc>::~vector() {
	clean();
}

//	Assignment operator overload

template <typename T, class Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator= (const vector& x) {
	size_t n = x.size();
	if (this == &x) {
		;
	} else if (n == 0) {
		clean();
	} else if (n <= size()) {
		destroy(_first + n, _last);
		_last = copy(_first, x.begin(), x.end());
	} else if (n <= capacity()) {
		_last = copy(_first, x.begin(), x.end());
	} else {
		clean();
		if (allocate(n))
			_last = copy(_first, x.begin(), x.end());
	}
	return *this;
}

}

#endif
