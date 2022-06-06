#ifndef ELEMENTS_ACCESS_HPP
# define ELEMENTS_ACCESS_HPP

#include "vector.hpp"

namespace ft
{

/*
Returns a reference to the element at position n in the vector
Does not check against bounds
*/
template < typename T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n) {
	return _first[n];
}

/*
Returns a const reference to the element at position n in the vector
Does not check against bounds
*/
template < typename T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const{
	return _first[n];
}

/*
Returns a reference to the element at position n in the vector
Signals if the requested position is out of range by throwing an out_of_range exception
*/
template < typename T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n) {
	if (n >= _last - _first)
		throw std::out_of_range("vector");
	return _first[n];
}

/*
Returns a const reference to the element at position n in the vector
Signals if the requested position is out of range by throwing an out_of_range exception
*/
template < typename T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
	if (n >= _last - _first)
		throw std::out_of_range("vector");
	return _first[n];
}

/*
Returns a reference to the first element in the vector
*/
template < typename T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::front() {
//		return *_first;
	return *(begin());
}

/*
Returns a const reference to the first element in the vector
*/
template < typename T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const {
	return *_first;
}

/*
Returns a reference to the last element in the vector
*/
template < typename T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::back() {
	return *(_last - 1);
}

/*
Returns a const reference to the last element in the vector
*/
template < typename T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const {
	return *(_last - 1);
}

}

#endif
