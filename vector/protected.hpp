#pragma once

#include "vector.hpp"

namespace ft
{

template <typename T, class Alloc>
bool vector<T, Alloc>::allocate(size_t n) {
	if (!n) {
		_first = _last = _end = nullptr;
		return false;
	} else if (n > max_size()) {
		throw std::length_error("vector");
	} else {
		_first = _last = _allocator.allocate(n, nullptr);
		_end = _first + n;
		return true;
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::destroy(pointer first, pointer last) {
	while (first != last) {
		_allocator.destroy(first++);
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::clean() {
	if (_first) {
		destroy(_first, _last);
		_allocator.deallocate(_first, capacity());
		_first = _last = _end = nullptr;
	}
}

template <typename T, class Alloc>
template <typename InputIt>
typename vector<T, Alloc>::pointer vector<T, Alloc>::copy(pointer P, InputIt first, InputIt last) {
	pointer temp = P;
	try {
		while (first != last) {
			_allocator.construct(P++, *first++);
		}
	} catch (...) {
		destroy(temp, P);
		throw;
	}
	return P;
}

template <typename T, class Alloc>
typename vector<T, Alloc>::pointer vector<T, Alloc>::fill(pointer P, size_t n, const T& x) {
	pointer temp = P;
	try {
		while (n-- > 0) {
			_allocator.construct(P++, x);
		}
	} catch (...) {
		destroy(temp, P);
		throw;
	}
	return P;
}

}
