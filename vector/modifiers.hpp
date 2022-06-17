#pragma once

#include "vector.hpp"

namespace ft
{

template <typename T, class Alloc>
void vector<T, Alloc>::clear() {
	if (_first) {
		destroy(_first, _last);
		_last = _first;
	}
}

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, const T &value) {
	;
}

template <typename T, class Alloc>
void vector<T, Alloc>::insert(iterator pos, size_type count, const T &value) {
	size_t max_size = this->max_size();
	size_t capacity = this->capacity();
	size_t size = this->size();

	if (count == 0) {
		;
	} else if (count > max_size - size) {
		throw std::length_error("vector");
	} else if ((size + count) < capacity) {
		size_t new_capacity = (max_size - (capacity / 2)) < capacity ? 0 : (capacity + (capacity / 2));
		if (new_capacity < size + count)
			new_capacity = size + count;
		pointer newPointer = _allocator.allocate(new_capacity, nullptr);
		pointer newLastPointer;
		newLastPointer = copy(newPointer, begin(), end());
		newLastPointer = fill(newLastPointer, count, value);
		if (_first) {
			clean();
		}
		_end = newPointer + new_capacity;
		_last = newPointer + size + count;
		_first = newPointer;
	} else {
		;
	}
}

template <typename T, class Alloc>
template<class InputIt>
void vector<T, Alloc>::insert(iterator pos, InputIt first, InputIt last) {

}

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pos) {

}

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last) {

}

template <typename T, class Alloc>
void vector<T, Alloc>::push_back(const T &value) {

}

template <typename T, class Alloc>
void vector<T, Alloc>::pop_back() {
	size_t n = size();
	if (n == 0) {
		;
	} else if (n == 1) {
		_allocator.destroy(_last);
		_last--;
	} else {
		_allocator.destroy(_last);
		_last--;
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::resize(size_type count) {

}

template <typename T, class Alloc>
void vector<T, Alloc>::resize(size_type count, T value) {

}

template <typename T, class Alloc>
void vector<T, Alloc>::swap(vector &other) {

}

}
