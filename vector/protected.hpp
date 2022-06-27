#ifndef PROTECTED_HPP
#define PROTECTED_HPP

#include "vector.hpp"

namespace ft
{

template <typename T, class Alloc>
bool vector<T, Alloc>::allocate(size_t n) {
	_first = _last = _end = nullptr;
	if (!n) {
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
void vector<T, Alloc>::clean() {
	if (_first) {
		destroy(_first, _last);
		_allocator.deallocate(_first, capacity());
	}
	_first = _last = _end = nullptr;
}

template <typename T, class Alloc>
void vector<T, Alloc>::destroy(pointer first, pointer last) {
	for (; first != last; ++first) {
		_allocator.destroy(first++);
	}
}

template <typename T, class Alloc>
template <typename InputIt>
typename vector<T, Alloc>::pointer vector<T, Alloc>::copy(pointer pos, InputIt first, InputIt last) {
	pointer temp = pos;
	try {
		for (; first != last; ++pos, ++first) {
			_allocator.construct(pos, *first);
		}
	} catch (...) {
		destroy(temp, pos);
		throw;
	}
	return pos;
}

template <typename T, class Alloc>
typename vector<T, Alloc>::pointer vector<T, Alloc>::fill(pointer pos, size_t n, const T& x) {
	pointer temp = pos;
	try {
		for (; 0 < n; --n, ++pos) {
			_allocator.construct(pos++, x);
		}
	} catch (...) {
		destroy(temp, pos);
		throw;
	}
	return pos;
}

template <typename T, class Alloc>
template<class It>
void vector<T, Alloc>::construct(It first, It last, int_iterator_tag) {
	size_type n = (size_type)first;
	if (allocate(n))
		_last = fill(_first, n, (T)last);
}

template <typename T, class Alloc>
template<class It>
void vector<T, Alloc>::construct(It first, It last, input_iterator_tag) {
	allocate(0);
	insert(begin(), first, last);
}

template <typename T, class Alloc>
template <class It>
void    vector<T, Alloc>::Insert(iterator pos, It first, It last, int_iterator_tag) {
	insert(pos, (size_type)first, (T)last);
}

template <typename T, class Alloc>
template <class It>
void    vector<T, Alloc>::Insert(iterator pos, It first, It last, input_iterator_tag) {
	for (; first != last; ++pos, ++first) {
		pos = insert(pos, *first);
	}
}

template <typename T, class Alloc>
template <class It>
void    vector<T, Alloc>::Insert(iterator pos, It first, It last, forward_iterator_tag)
{
	size_t      max_size = this->max_size();
	size_t      capacity = this->capacity();
	size_t      size = this->size();
	size_type   n = 0;

	Distance(first, last, n);
	if (n == 0) {
		;
	} else if (n > max_size - size) {
		throw std::length_error("vector");
	} else if (size + n > capacity) {
		size_type new_capacity = max_size - capacity / 2 < capacity ? 0 : capacity * 2;
		if (new_capacity < size + n)
			new_capacity = size + n;
		pointer new_first = _allocator.allocate(new_capacity, nullptr);
		pointer new_last;
		try {
			new_last = copy(new_first, begin(), pos);
			new_last = copy(new_last, first, last);
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
		_last = new_first + size + n;
		_end = new_first + new_capacity;
	} else if (n > (size_type)(end() - pos)) {
		copy(pos.base() + n, pos, end());
		It mid = first;
		advance(mid, end() - pos);
		try {
			copy(_last, mid, last);
		} catch (...) {
			destroy(pos.base() + n, _last + n);
			throw;
		}
		_last += n;
		copy_forward(pos, first, mid);
	} else {
		iterator end = end();
		_last = copy(_last, end - n, _end);
		copy_backward(pos, end - n, end);
		copy(pos, first, last);
	}
}

}

#endif // PROTECTED_HPP
