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
		pointer new_first = base::allocator.allocate(new_capacity, nullptr);
		pointer new_last;
		try {
			new_last = Copy(new_first, begin(), pos);
			new_last = Fill(new_last, count, value);
			Copy(new_last, pos, end());
		} catch (...) {
			Destroy(new_first, new_last);
			base::allocator.deallocate(new_first, new_capacity);
			throw;
		}
		if (_first) {
			Clean();
		}
		_first = new_first;
		_last = new_first + size + count;
		_end = new_first + new_capacity;
	}
	else if ((size_type)(end() - pos) < count) {
		Copy(pos.base(), pos, end());
		try {
			Fill(_last, count - (end() - pos), value);
		} catch (...) {
			Destroy(pos.base() + count, _last + count);
			throw;
		}
		_last += count;
		Fill(pos, pos + count, value);
	} else {
		iterator end = end();
		_last = Copy(_last, end - count, _end);
		copy_backward(pos, end - count, end);
		fill(pos, pos + count, value);
	}
}

template <typename T, class Alloc>
template<class InputIt>
void vector<T, Alloc>::insert(iterator pos, InputIt first, InputIt last) {
	Insert(pos, first, last, Iter_cat(first));
}

// Removes the element at pos
template <typename T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pos) {
	Copy(pos, pos + 1, end());
	Destroy(_last - 1, _last);
	_last--;
	return (pos);
}


// Removes the elements in the range
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

#endif //VECTOR_MODIFIERS_HPP
