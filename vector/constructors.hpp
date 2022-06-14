#ifndef CONSTRUCTORS_HPP
#define CONSTRUCTORS_HPP

#include "vector.hpp"

namespace ft
{

//	Constructors

template <typename T, class Alloc>
vector<T, Alloc>::vector(const allocator_type&):
	_first(nullptr), _last(nullptr), _end(nullptr) {
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(size_t n, const allocator_type&) {
	if (!n) {
		_first = _last = _end = nullptr;
	} else if (n > max_size()) {
		throw std::length_error("vector");
	}
	else {
		_first = _allocator.allocate(n, nullptr);
		_last = _end = _first + n;
	}
}

template <typename T, class Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(InputIterator first, InputIterator last) {
	size_t n = last - first;
	if (!n) {
		_first = _last = _end = nullptr;
	} else if (n > max_size()) {
		throw std::length_error("vector");
	} else {
		_first = _last = _allocator.allocate(n, nullptr);
		_end = _first + n;
		try {
			for (; 0 < n; --n) {
				_allocator.construct(_last++, *first++);
			}
		} catch (...) {
			throw;
		}
	}
}

template <typename T, class Alloc>
vector<T, Alloc>::vector(const vector& x):
	_first(nullptr), _last(nullptr), _end(nullptr) {
	*this = x;
}

//	Destructor

template <typename T, class Alloc>
vector<T, Alloc>::~vector() {
	size_t n = _end - _first;
	if (_first != nullptr) {
		_allocator.deallocate(_first, n);
	}
}

//	Assignment operator overload

template <typename T, class Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator= (const vector& x) {
	if (this == &x) {
		;
	} else if (x.size() == 0) {
//		clean();
		std::cout << "hello\n";
;
	} else if (x.size() < size()) {
//		destroy(_first + x.size(), _end);
;
	} else if (x.size() < capacity()) {
		;
	} else {
		size_t n = x.size();
		_first = _last = _allocator.allocate(n, nullptr);
		_end = _first + n;
		try {
			pointer temp = x._first;
			for (; 0 < n; --n) {
				_allocator.construct(_last++, *temp++);
			}
		} catch (...) {
			throw;
		}
	}
	return *this;
}

}

#endif
