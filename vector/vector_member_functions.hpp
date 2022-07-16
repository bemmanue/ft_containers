#ifndef VECTOR_MEMBER_FUNCTIONS_HPP
#define VECTOR_MEMBER_FUNCTIONS_HPP

#include "vector_base.hpp"

namespace ft {

template<typename T, class Alloc>
vector<T, Alloc>::vector() : base() {
	Allocate(0);
}

template<typename T, class Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc) : base() {
	Allocate(0);
}

template<typename T, class Alloc>
vector<T, Alloc>::vector(size_type count, const T& value, const allocator_type&) : base() {
	if (Allocate(count))
		_last = Fill(_first, count, value);
}

template<typename T, class Alloc>
template<class It>
vector<T, Alloc>::vector(It first, It last, const allocator_type& alloc) : base() {
	Construct(first, last, Iter_cat(first));
}

template<typename T, class Alloc>
vector<T, Alloc>::vector(const vector& x) : base() {
	if (Allocate(x.size())) {
		_last = Copy(_first, x.begin(), x.end());
	}
}

template<typename T, class Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator= (const vector_type& x) {
	size_t n = x.size();

	if (this == &x) {
		;
	} else if (n == 0) {
		Clean();
	} else if (n <= size()) {
		pointer Q = copy_forward(x.begin(), x.end(), _first);
		Destroy(Q, _last);
		_last = _first + n;
	} else if (n <= capacity()) {
		const_iterator S = x.begin() + size();
		copy_forward(x.begin(), S, _first);
		_last = Copy(_last, S, x.end());
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

#endif //VECTOR_MEMBER_FUNCTIONS_HPP
