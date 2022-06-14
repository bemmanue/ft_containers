#ifndef PROTECTED_HPP
# define PROTECTED_HPP

#include "vector.hpp"

namespace ft
{

template <typename T, class Alloc>
bool vector<T, Alloc>::allocate(size_t n) {
	if (!n) {
		_first = _last = _end = nullptr;
		return false;
	} else {
		_first = _allocator.allocate(n, nullptr);
		_last = _first;
		_end = _first + n;
		return true;
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::destroy(pointer first, pointer last) {
	for (; first != last; first++) {
		_allocator.destroy(first);
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::clean() {
	if (_first) {
//		destroy(_first, _last);
//		_allocator.deallocate(_first, capacity());
//		_first = _last = _end = nullptr;
	}
}

}

#endif
