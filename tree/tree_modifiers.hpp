#ifndef FT_CONTAINERS_TREE_MODIFIERS_HPP
#define FT_CONTAINERS_TREE_MODIFIERS_HPP

#include "tree.hpp"

namespace ft {

template<class T>
typename tree<T>::pairib tree<T>::insert(const value_type& v) {

}

template<class T>
typename tree<T>::tree_iterator tree<T>::insert(tree_iterator P, const value_type& v) {

}

template<class T>
template<class It>
void tree<T>::insert(It F, It L) {

}

template<class T>
typename tree<T>::tree_iterator tree<T>::erase(tree_iterator P) {

}

template<class T>
typename tree<T>::tree_iterator tree<T>::erase(tree_iterator F, tree_iterator L) {

}

template<class T>
typename tree<T>::size_type tree<T>::erase(const key_type& x) {

}

template<class T>
void tree<T>::erase(const key_type *F, const key_type *L) {

}

template<class T>
void tree<T>::clear() {

}

template<class T>
typename tree<T>::tree_iterator tree<T>::find(const key_type& Kv) {

}

template<class T>
typename tree<T>::tree_const_iterator tree<T>::find(const key_type& Kv) const {

}

template<class T>
typename tree<T>::size_type tree<T>::count(const key_type& Kv) const {

}

template<class T>
typename tree<T>::tree_iterator tree<T>::lower_bound(const key_type& Kv) {

}

template<class T>
typename tree<T>::tree_const_iterator tree<T>::lower_bound(const key_type& Kv) const {

}

template<class T>
typename tree<T>::tree_iterator tree<T>::upper_bound(const key_type& Kv) {

}

template<class T>
typename tree<T>::tree_const_iterator tree<T>::upper_bound(const key_type& Kv) const {

}

template<class T>
typename tree<T>::pairii tree<T>::equal_range(const key_type& Kv) {

}

template<class T>
typename tree<T>::paircc tree<T>::equal_range(const key_type& Kv) const {

}

template<class T>
void tree<T>::swap(Myt& x) {

}

}

#endif //FT_CONTAINERS_TREE_MODIFIERS_HPP
