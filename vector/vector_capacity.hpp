#ifndef VECTOR_CAPACITY_HPP
#define VECTOR_CAPACITY_HPP

#include "vector_base.hpp"

namespace ft {

//Checks if the container has no elements
template<typename T, class Alloc>
bool vector<T, Alloc>::empty() const {
	return (size() == 0);
}

//Returns the number of elements in the container
template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const {
	return (_first == (void *)0 ? 0 : _last - _first);
}

//Returns the maximum number of elements the container is able to hold
//due to system or library implementation limitations
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

//Returns the number of elements that the container has currently allocated space for
template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const {
	return (_first == 0 ? 0 : _end - _first);
}

}

#endif //VECTOR_CAPACITY_HPP
