#ifndef VECTOR_PROTECTED_HPP
#define VECTOR_PROTECTED_HPP

#include "vector_base.hpp"

namespace ft {

template <typename T, class Alloc>
bool vector<T, Alloc>::Allocate(size_t n) {
	_first = _last = _end = 0;
	if (!n) {
		return false;
	} else if (n > max_size()) {
		throw std::length_error("vector");
	} else {
		_first = _last = base::allocator.allocate(n, (void *)0);
		_end = _first + n;
		return true;
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::Clean() {
	if (_first) {
		Destroy(_first, _last);
		base::allocator.deallocate(_first, capacity());
	}
	_first = _last = _end = 0;
}

template <typename T, class Alloc>
void vector<T, Alloc>::Destroy(pointer first, pointer last) {
	for (; first != last; ++first) {
		base::allocator.destroy(first);
	}
}

template <typename T, class Alloc>
template <typename InputIt>
typename vector<T, Alloc>::pointer vector<T, Alloc>::Copy(pointer pos, InputIt first, InputIt last) {
	pointer temp = pos;
	try {
		for (; first != last; ++pos, ++first) {
			base::allocator.construct(pos, *first);
		}
	} catch (...) {
		Destroy(temp, pos);
		throw;
	}
	return pos;
}

template <typename T, class Alloc>
typename vector<T, Alloc>::pointer vector<T, Alloc>::Fill(pointer pos, size_t n, const T& x) {
	pointer temp = pos;
	try {
		for (; 0 < n; --n, ++pos) {
			base::allocator.construct(pos, x);
		}
	} catch (...) {
		Destroy(temp, pos);
		throw;
	}
	return pos;
}

template<typename T, class Alloc>
template <class It>
void vector<T, Alloc>::Assign(It first, It last, int_iterator_tag) {
	assign((size_type)first, (T)last);
}

template<typename T, class Alloc>
template<class It>
void vector<T, Alloc>::Assign(It first, It last, input_iterator_tag) {
	erase(begin(), end());
	insert(begin(), first, last);
}

template <typename T, class Alloc>
template<class It>
void vector<T, Alloc>::Construct(It first, It last, int_iterator_tag) {
	size_type n = first;
	if (Allocate(n))
		_last = Fill(_first, n, (T) last);
}

template <typename T, class Alloc>
template<class It>
void vector<T, Alloc>::Construct(It first, It last, input_iterator_tag) {
	Allocate(0);
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
		pointer new_first = base::allocator.allocate(new_capacity, (void *)0);
		pointer new_last;
		try {
			new_last = Copy(new_first, begin(), pos);
			new_last = Copy(new_last, first, last);
			Copy(new_last, pos, end());
		} catch (...) {
			Destroy(new_first, new_last);
			base::allocator.deallocate(new_first, new_capacity);
			throw;
		}
		if (_first) {
			Clean();
		}
		_end = new_first + new_capacity;
		_last = new_first + size + n;
		_first = new_first;
	} else if (n > (size_type)(end() - pos)) {
		Copy(pos.base() + n, pos, end());
		It mid = first;
		advance(mid, end() - pos);
		try {
			Copy(_last, mid, last);
		} catch (...) {
			Destroy(pos.base() + n, _last + n);
			throw;
		}
		_last += n;
		copy_forward(first, mid, pos);
	} else if (n > 0) {
		iterator end = this->end();
		_last = Copy(_last, end - n, end);
		copy_backward(pos, end - n, end);
		copy_forward(first, last, pos);
	}
}

}

#endif //VECTOR_PROTECTED_HPP
