#ifndef FT_CONTAINERS_TREE_CONSTRUCTORS_HPP
#define FT_CONTAINERS_TREE_CONSTRUCTORS_HPP

#include "tree.hpp"

namespace ft {

template<class T>
tree<T>::tree(const key_compare& parg, const allocator_type& Al) {

}

template<class T>
tree<T>::tree(const value_type *F, const value_type *L, const key_compare& parg, const allocator_type& Al)
		: Mybase(parg, Al) {

}

template<class T>
tree<T>::tree(const Myt& x) {

}

template<class T>
tree<T>::~tree() {

}

template<class T>
typename tree<T>::Myt& tree<T>::operator=(const Myt& x) {

}

}

#endif //FT_CONTAINERS_TREE_CONSTRUCTORS_HPP
