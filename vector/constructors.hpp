#ifndef CONSTRUCTORS_HPP
#define CONSTRUCTORS_HPP

#include "vector.hpp"
#include "../algorithm/copy.hpp"

namespace ft {

template <typename T, class Alloc>
vector<T, Alloc>::vector(const allocator_type&) : base() {
	allocate(0);
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(size_t n, const allocator_type&) : base() {
	if (allocate(n))
		_last = fill(_first, n, T());
}

template <typename T, class Alloc>
template <class It>
vector<T, Alloc>::vector(It first, It last) : base() {
	construct(first, last, Iter_cat(first));
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(const vector& x) : base() {
	if (allocate(x.size())) {
		_last = copy(_first, x.begin(), x.end());
	}
}

template <typename T, class Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator= (const vector& x) {
	size_t n = x.size();

	if (this == &x) {
		;
	} else if (n == 0) {
		clean();
	} else if (n <= size()) {
		destroy(_first + n, _last);
		_last = copy_forward(_first, x.begin(), x.end());
	} else if (n <= capacity()) {
		_last = copy(_first, x.begin(), x.end());
	} else {
		clean();
		if (allocate(n)) {
			_last = copy(_first, x.begin(), x.end());
		}
	}
	return *this;
}

template <typename T, class Alloc>
vector<T, Alloc>::~vector() {
	clean();
}

}

#endif // CONSTRUCTORS_HPP
