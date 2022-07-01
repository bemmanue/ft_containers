#ifndef CONSTRUCTORS_HPP
#define CONSTRUCTORS_HPP

#include "vector.hpp"

namespace ft {

template<typename T, class Alloc>
vector<T, Alloc>::vector(const allocator_type&) : base() {
	Allocate(0);
}

template<typename T, class Alloc>
vector<T, Alloc>::vector(size_t n, const allocator_type&) : base() {
	if (Allocate(n))
		_last = Fill(_first, n, T());
}

template<typename T, class Alloc>
template<class It>
vector<T, Alloc>::vector(It first, It last) : base() {
	Construct(first, last, Iter_cat(first));
}

template<typename T, class Alloc>
vector<T, Alloc>::vector(const vector& x) : base() {
	if (Allocate(x.size())) {
		_last = Copy(_first, x.begin(), x.end());
	}
}

template<typename T, class Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator= (const vector& x) {
	size_t n = x.size();

	if (this == &x) {
		;
	} else if (n == 0) {
		Clean();
	} else if (n <= size()) {
		Destroy(_first + n, _last);
		_last = copy_forward(x.begin(), x.end(), _first);
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

template<typename T, class Alloc>
vector<T, Alloc>::~vector() {
	Clean();
}

template<typename T, class Alloc>
void vector<T, Alloc>::assign(size_type count, const T& value) {
	T x = value;

	erase(begin(), end());
	insert(begin(), count, x);
}

template<typename T, class Alloc>
template<class InputIt>
void vector<T, Alloc>::assign(InputIt first, InputIt last) {
	Assign(first, last, Iter_cat(first));
}

template<typename T, class Alloc>
typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const {
	return base::allocator;
}

}

#endif // CONSTRUCTORS_HPP
