#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>

namespace ft
{

template < class T, class Alloc = std::allocator<T> > class vector
{
public:
	typedef T											value_type;
	typedef std::allocator<T>							allocator_type;
	typedef typename std::allocator<T>::size_type		size_type;
	typedef typename std::allocator<T>::difference_type	difference_type;
	typedef typename std::allocator<T>::reference		reference;
	typedef typename std::allocator<T>::const_reference	const_reference;
	typedef typename std::allocator<T>::pointer			pointer;
	typedef typename std::allocator<T>::const_pointer	const_pointer;
//	iterator;
//	const_iterator;
//	reverse_iterator;
//	const_reverse_iterator;

	pointer				_first;
	pointer				_last;
	allocator_type		_allocator;

	explicit vector(const allocator_type& alloc = allocator_type());
	explicit vector(size_t n, const allocator_type& alloc = allocator_type());
	template <class InputIterator>
		vector(InputIterator first, InputIterator last);
	vector(const vector& x);
	~vector();
	vector& operator= (const vector& x);

///*Elements access*/
	reference 			operator[] (size_type n);
	const_reference		operator[] (size_type n) const;
	reference			at(size_type n);
	const_reference		at(size_type n) const;
	reference			front();
	const_reference		front() const;
	reference 			back();
	const_reference 	back() const;

///*Iterators*/
	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;
};

///*Constructors*/

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

///*Destructor*/

template < typename T, class Alloc >
vector<T, Alloc>::~vector() {
	size_t n = _last - _first;
	if (_first != nullptr)
		_allocator.deallocate(_first, n);
}

///*Assignment operator overload*/

//Copies all the elements from x into the container
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

///*Element access*/

//Returns a reference to the element at position n in the vector
//Does not check against bounds
template < typename T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n) {
	return _first[n];
}

//Returns a const reference to the element at position n in the vector
//Does not check against bounds
template < typename T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const{
	return _first[n];
}

//Returns a reference to the element at position n in the vector
//Signals if the requested position is out of range by throwing an out_of_range exception
template < typename T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n) {
	if (n >= _last - _first)
		throw std::out_of_range("vector");
	return _first[n];
}

//Returns a const reference to the element at position n in the vector
//Signals if the requested position is out of range by throwing an out_of_range exception
template < typename T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
	if (n >= _last - _first)
		throw std::out_of_range("vector");
	return _first[n];
}

//Returns a reference to the first element in the vector
template < typename T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::front() {
	return *_first;
}

//Returns a const reference to the first element in the vector
template < typename T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const {
	return *_first;
}

//Returns a reference to the last element in the vector
template < typename T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::back() {
	return *_last;
}

//Returns a const reference to the last element in the vector
template < typename T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const {
	return *_last;
}

}

#endif
