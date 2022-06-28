#ifndef CONSTRUCTORS_HPP
#define CONSTRUCTORS_HPP

#include "vector.hpp"

namespace ft {

template <typename T, class Alloc>
vector<T, Alloc>::vector(const allocator_type&) : base() {
	Allocate(0);
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(size_t n, const allocator_type&) : base() {
	if (Allocate(n))
		_last = Fill(_first, n, T());
}

template <typename T, class Alloc>
template <class It>
vector<T, Alloc>::vector(It first, It last) : base() {
	Construct(first, last, Iter_cat(first));
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(const vector& x) : base() {
	if (Allocate(x.size())) {
		_last = Copy(_first, x.begin(), x.end());
	}
}

template <typename T, class Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator= (const vector& x) {
	size_t n = x.size();

	if (this == &x) {
		;
	} else if (n == 0) {
		Clean();
	} else if (n <= size()) {
		Destroy(_first + n, _last);
		_last = copy_forward(_first, x.begin(), x.end());
	} else if (n <= capacity()) {
		_last = Copy(_first, x.begin(), x.end());
	} else {
		Clean();
		if (Allocate(n)) {
			_last = Copy(_first, x.begin(), x.end());
		}
	}
	return *this;
}

template <typename T, class Alloc>
vector<T, Alloc>::~vector() {
	Clean();
}

}

#endif // CONSTRUCTORS_HPP
