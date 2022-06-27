#ifndef MODIFIERS_HPP
#define MODIFIERS_HPP

#include "vector.hpp"
#include "../algorithm/copy.hpp"

namespace ft
{

template <typename T, class Alloc>
void vector<T, Alloc>::clear() {
	erase(begin(), end());
}

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, const T &value) {
	size_type off = size() == 0 ? 0 : pos - begin();
	insert(pos, 1, value);
	return (begin() + off);
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
	} else if ((size + count) > capacity) {
		size_t new_capacity = (max_size - (capacity / 2)) < capacity ? 0 : (capacity * 2);
		if (new_capacity < size + count)
			new_capacity = size + count;
		pointer new_first = _allocator.allocate(new_capacity, nullptr);
		pointer new_last;
		try {
			new_last = copy(new_first, begin(), pos);
			new_last = fill(new_last, count, value);
			copy(new_last, pos, end());
		} catch (...) {
			destroy(new_first, new_last);
			_allocator.deallocate(new_first, new_capacity);
			throw;
		}
		if (_first) {
			clean();
		}
		_first = new_first;
		_last = new_first + size + count;
		_end = new_first + new_capacity;
	}
	else if ((size_type)(end() - pos) < count) {
		copy(pos.base(), pos, end());
		try {
			fill(_last, count - (end() - pos), value);
		} catch (...) {
			destroy(pos.base() + count, _last + count);
			throw;
		}
		_last += count;
		fill(pos, pos + count, value);
	} else {
		iterator end = end();
		_last = copy(_last, end - count, _end);
		copy_backward(pos, end - count, end);
		fill(pos.base(), pos + count, value);
	}
}

template <typename T, class Alloc>
template<class InputIt>
void vector<T, Alloc>::insert(iterator pos, InputIt first, InputIt last) {
	Insert(pos, first, last, Iter_cat(first));
}

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pos) {
	copy(pos, pos + 1, end());
	destroy(_last - 1, _last);
	_last--;
	return (pos);
}

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last) {
	if (first != last) {
		pointer P = copy(first.base(), last, end());
		destroy(P, _last);
		_last = P;
	}
	return first;
}

template <typename T, class Alloc>
void vector<T, Alloc>::push_back(const T &value) {
	insert(end(), value);
}

template <typename T, class Alloc>
void vector<T, Alloc>::pop_back() {
	erase(end() - 1);
}

template <typename T, class Alloc>
void vector<T, Alloc>::resize(size_type count) {
	resize(count, T());
}

template <typename T, class Alloc>
void vector<T, Alloc>::resize(size_type count, T value) {
	if (size() < count) {
		insert(end(), count - size(), value);
	} else if (count < size()) {
		erase(begin() + count, end());
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::swap(vector& other) {
	if (base::allocator_type == other.allocator_type) {
		std::swap(_first, other._first);
		std::swap(_last, other._last);
		std::swap(_end, other._end);
	} else {
		vector temp = *this;
		*this = other;
		other = this;
	}
}

}

#endif
