#include "vector.hpp"

namespace ft
{

//	Constructors

	template < typename T, class Alloc >
	vector<T, Alloc>::vector(const allocator_type&) {
		_first = nullptr;
		_last = nullptr;
	}

	template < typename T, class Alloc >
	vector<T, Alloc>::vector(size_t n,  const allocator_type&) {
		_first = _allocator.allocate(n);
		_last = _first + n;
	}

	template < typename T, class Alloc >
	template < class InputIterator >
	vector<T, Alloc>::vector(InputIterator first, InputIterator last) {
		size_t n = last - first;
		_first = _allocator.allocate(n);
		_last = _first + n;
		pointer temp = _first;
		for (int i = 0; i < n; i++) {
			_allocator.construct(temp++, *first++);
		}
	}

	template < typename T, class Alloc >
	vector<T, Alloc>::vector(const vector& x) {
		*this = x;
	}

//	Destructor

	template < typename T, class Alloc >
	vector<T, Alloc>::~vector() {
		size_t n = _last - _first;
		if (_first != nullptr)
			_allocator.deallocate(_first, n);
	}

//	Assignment operator overload

	template < typename T, class Alloc >
	vector<T, Alloc>& vector<T, Alloc>::operator= (const vector& x) {
		if (x._first != nullptr) {
			size_t n = x._last - x._first;
			_first = _allocator.allocate(n);
			_last = _first + n;
			pointer temp = _first;
			for (int i = 0; i < n; i++) {
				_allocator.construct(temp++, 7);
			}
		}
		return *this;
	}

}