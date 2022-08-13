#ifndef VECTOR_CAPACITY_HPP
#define VECTOR_CAPACITY_HPP

#include "vector_base.hpp"

namespace ft {

template<typename T, class Alloc>
bool vector<T, Alloc>::empty() const {
	return (size() == 0);
}

template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const {
	return (_first == (void *)0 ? 0 : _last - _first);
}

template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const {
	return base::allocator.max_size();
}

template<typename T, class Alloc>
void vector<T, Alloc>::reserve(size_type n) {
	if (n > max_size())
		throw std::length_error("vector");
	else if (capacity() < n) {
		pointer new_first = base::allocator.allocate(n, (void *)0);
		try {
			Copy(new_first, begin(), end());
		} catch (...) {
			base::allocator.deallocate(new_first, n);
			throw;
		}
		if (_first) {
			Destroy(_first, _last);
			base::allocator.deallocate(_first, capacity());
		}
		_end = new_first + n;
		_last = new_first + size();
		_first = new_first;
	}
}

template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const {
	return (_first == 0 ? 0 : _end - _first);
}

}

#endif //VECTOR_CAPACITY_HPP
