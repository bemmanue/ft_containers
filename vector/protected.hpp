#ifndef PROTECTED_HPP
#define PROTECTED_HPP

#include "vector.hpp"

namespace ft
{

template <typename T, class Alloc>
bool vector<T, Alloc>::allocate(size_t n) {
	if (!n) {
		_first = _last = _end = nullptr;
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
		_first = _last = _end = nullptr;
	}
}

template <typename T, class Alloc>
void vector<T, Alloc>::destroy(pointer first, pointer last) {
	while (first != last) {
		_allocator.destroy(first++);
	}
}

template <typename T, class Alloc>
template <typename InputIt>
typename vector<T, Alloc>::pointer vector<T, Alloc>::copy(pointer P, InputIt first, InputIt last) {
	pointer temp = P;
	try {
		while (first != last) {
			_allocator.construct(P++, *first++);
		}
	} catch (...) {
		destroy(temp, P);
		throw;
	}
	return P;
}

template <typename T, class Alloc>
typename vector<T, Alloc>::pointer vector<T, Alloc>::fill(pointer P, size_t n, const T& x) {
	pointer temp = P;
	try {
		while (n-- > 0) {
			_allocator.construct(P++, x);
		}
	} catch (...) {
		destroy(temp, P);
		throw;
	}
	return P;
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

//    template <typename T, class Alloc>
//    template <class It>
//    void    vector<T, Alloc>::Insert(iterator pos, It first, It last, Int_iterator_tag)
//    {
//        insert(pos, (size_type)first, (T)last);
//    }

template <typename T, class Alloc>
template <class It>
void    vector<T, Alloc>::Insert(iterator pos, It first, It last, input_iterator_tag)
{
	while (first != last)
	{
		pos = insert(pos++, *first++);
	}
}

template <typename T, class Alloc>
template <class It>
void    vector<T, Alloc>::Insert(iterator pos, It first, It last, forward_iterator_tag)
{
	size_t      max_size = this->max_size();
	size_t      capacity = this->capacity();
	size_t      size = this->size();
	size_type   count = 0;

	Distance(first, last, count);
	if (count == 0)
	{
		;
	}
	else if (max_size - size < count)
	{
		throw std::length_error("vector");
	}
	else if (capacity < size + count)
	{
		size_type new_capacity = max_size - capacity / 2 < capacity ? 0 : capacity * 2;
		if (new_capacity < size + count)
			new_capacity = size + count;
		pointer new_first = _allocator.allocate(new_capacity, nullptr);
		pointer new_last;
		try
		{
			new_last = copy(new_first, begin(), pos);
			new_last = copy(new_first, first, last);
			copy(new_last, pos, end());
		}
		catch (...)
		{
			destroy(new_first, new_last);
			_allocator.deallocate(new_first, new_capacity);
			throw;
		}
		if (_first)
		{
			clean();
		}
		_first = new_first;
		_last = new_first + size + count;
		_end = new_first + new_capacity;
	}
	else if ((size_type)(end() - pos) < count)
	{
		copy(pos.base(), pos, end());
		It mid = first;
		advance(mid, end() - pos);
		try
		{
			copy(_last, mid, last);
		}
		catch (...)
		{
			destroy(pos.base() + count, _last + count);
			throw;
		}
		_last += count;
		copy(pos, first, mid);
	}
	else
	{
		iterator end = end();
		_last = copy(_last, end - count, _end);
		copy_backward(pos, end - count, end);
		copy(pos, first, last);
	}
}

}

#endif // PROTECTED_HPP
