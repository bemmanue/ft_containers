#ifndef CAPASITY_HPP
# define CAPASITY_HPP

#include "vector.hpp"

namespace ft
{

//Checks if the container has no elements
template<typename T, class Alloc>
bool vector<T, Alloc>::empty() const {
	return (size() == 0);
}

//Returns the number of elements in the container
template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const {
	return (_first == 0 ? 0 : _last - _first);
}

//Returns the maximum number of elements the container is able to hold
// due to system or library implementation limitations
template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const {
	Alloc a;
	return a.max_size();
}

template<typename T, class Alloc>
void vector<T, Alloc>::reserve(size_type new_cap) {
	if (new_cap > max_size())
		throw std::length_error("vector");
	else if (capacity() < new_cap) {
		Alloc a;
		pointer Q = a.allocate(new_cap, (void *)0);
		try {
			;
		}
	}
}

//Returns the number of elements that the container has currently allocated space for
template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const {
	return (_first == 0 ? 0 : _end - _first);
}

}

#endif
