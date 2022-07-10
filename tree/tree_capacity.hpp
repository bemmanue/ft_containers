#ifndef FT_CONTAINERS_TREE_CAPACITY_HPP
#define FT_CONTAINERS_TREE_CAPACITY_HPP

#include "tree_base.hpp"

namespace ft {

template<class T>
typename tree<T>::size_type tree<T>::size() const {
	return (Size);
}

template<class T>
typename tree<T>::size_type tree<T>::max_size() const {
	return (Alval.max_size());
}

template<class T>
bool tree<T>::empty() const {
	return (size() == 0);
}

}

#endif //FT_CONTAINERS_TREE_CAPACITY_HPP
