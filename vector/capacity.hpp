#ifndef CAPACITY_HPP
# define CAPACITY_HPP

#include "vector.hpp"

namespace ft
{

//Checks if the container has no elements
template<typename T, class Alloc>
bool vector<T, Alloc>::empty() const {
	return (size() == 0);
}

//Returns the number of elements in the container
template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const {
	return (_first == nullptr ? 0 : _last - _first);
}

//Returns the maximum number of elements the container is able to hold
// due to system or library implementation limitations
template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const {
	return _allocator.max_size();
}

template<typename T, class Alloc>
void vector<T, Alloc>::reserve(size_type n) {
	if (n > max_size())
		throw std::length_error("vector");
	else if (capacity() < n) {
		pointer newPointer = _allocator.allocate(n, nullptr);
		pointer temp = newPointer;
		for (int i = 0; i < size(); i++) {
			_allocator.construct(temp++, *_first++);
		}
		_first = newPointer;
		_last = _first + size();
		_end = _first + n;
	}
}

//Returns the number of elements that the container has currently allocated space for
template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const {
	return (_first == 0 ? 0 : _end - _first);
}

}

#endif
