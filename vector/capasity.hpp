#ifndef CAPASITY_HPP
# define CAPASITY_HPP

#include "vector.hpp"

namespace ft
{

template<typename T, class Alloc>
bool vector<T, Alloc>::empty() const {
	return true;
}

template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const {

}

template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const {

}

template<typename T, class Alloc>
void vector<T, Alloc>::reserve(size_type new_cap) {

}

template<typename T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const {

}

}

#endif
