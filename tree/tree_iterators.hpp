#ifndef FT_CONTAINERS_TREE_ITERATORS_HPP
#define FT_CONTAINERS_TREE_ITERATORS_HPP

#include "tree.hpp"

namespace ft {

template<class T>
typename tree<T>::tree_iterator tree<T>::begin() {
	return (tree_iterator(Lmost()));
}

template<class T>
typename tree<T>::const_tree_iterator tree<T>::begin() const {
	return (const_tree_iterator(Lmost()));
}

template<class T>
typename tree<T>::tree_iterator tree<T>::end() {
	return (tree_iterator(Head));
}

template<class T>
typename tree<T>::const_tree_iterator tree<T>::end() const {
	return (const_tree_iterator(Head));
}

template<class T>
typename tree<T>::tree_iterator tree<T>::rbegin() {
	return (reverse_iterator(end()));
}

template<class T>
typename tree<T>::const_tree_iterator tree<T>::rbegin() const {
	return (const_reverse_iterator(end()));
}

template<class T>
typename tree<T>::tree_iterator tree<T>::rend() {
	return (reverse_iterator(begin()));
}

template<class T>
typename tree<T>::const_tree_iterator tree<T>::rend() const {
	return (const_reverse_iterator(begin()));
}

}

#endif //FT_CONTAINERS_TREE_ITERATORS_HPP
