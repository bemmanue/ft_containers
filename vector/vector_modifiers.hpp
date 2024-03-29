#ifndef VECTOR_MODIFIERS_HPP
#define VECTOR_MODIFIERS_HPP

#include "vector_base.hpp"

namespace ft {

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
void vector<T, Alloc>::insert(iterator pos, size_type count, const T& value) {
	T x = value;
	size_type N = capacity();

	if (count == 0) {
		;
	} else if (max_size() - size() < count) {
		throw std::length_error("vector");
	} else if (N < size() + count) {
		N = (max_size() - N < N) ?
			0 : N + N;
		if (N < size() + count)
			N = size() + count;
		pointer new_first = base::allocator.allocate(N);
		pointer new_last;
		try {
			new_last = Copy(new_first, begin(), pos);
			new_last = Fill(new_last, count, x);
			Copy(new_last, pos, end());
		} catch (...) {
			Destroy(new_first, new_last);
			base::allocator.deallocate(new_first, N);
			throw;
		}
		if (_first) {
			Destroy(_first, _last);
			base::allocator.deallocate(_first, _end - _first);
		}
		_end = new_first + N;
		_last = new_first + size() + count;
		_first = new_first;
	} else if ((size_type) (end() - pos) < count) {
		Copy(pos.base(), pos, end());
		try {
			Fill(_last, count - (end() - pos), x);
		} catch (...) {
			Destroy(pos.base() + count, _last + count);
			throw;
		}
		_last += count;
		ft::fill(pos, end() - count, x);
	} else {
		iterator new_end = end();
		_last = Copy(_last, new_end - count, new_end);
		std::copy_backward(pos, new_end - count, new_end);
		ft::fill(pos, pos + count, x);
	}
}

template <typename T, class Alloc>
template<class InputIt>
void vector<T, Alloc>::insert(iterator pos, InputIt first, InputIt last) {
	Insert(pos, first, last, Iter_cat(first));
}

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pos) {
	copy_forward(pos + 1, end(), pos);
	Destroy(_last - 1, _last);
	_last--;
	return (pos);
}

template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last) {
	if (first != last) {
		pointer new_last = Copy(first.base(), last, end());
		Destroy(new_last, _last);
		_last = new_last;
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
void vector<T, Alloc>::resize(size_type n, T value) {
	if (size() < n) {
		insert(end(), n - size(), value);
	} else if (n < size()) {
		erase(begin() + n, end());
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::swap(vector_type& other) {
	if (base::allocator == other.allocator) {
		std::swap(_first, other._first);
		std::swap(_last, other._last);
		std::swap(_end, other._end);
	} else {
		vector_type temp = *this;
		*this = other;
		other = temp;
	}
}

}

#endif //VECTOR_MODIFIERS_HPP
