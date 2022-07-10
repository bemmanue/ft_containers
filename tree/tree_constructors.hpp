#ifndef FT_CONTAINERS_TREE_CONSTRUCTORS_HPP
#define FT_CONTAINERS_TREE_CONSTRUCTORS_HPP

#include "tree.hpp"

namespace ft {

template<class T>
tree<T>::tree(const key_compare& parg, const allocator_type& Al)
		: Mybase(parg, Al) {
	Init();
}

template<class T>
tree<T>::tree(const value_type *F, const value_type *L, const key_compare& parg, const allocator_type& Al)
		: Mybase(parg, Al) {
	Init();
	insert(F, L);
}

template<class T>
tree<T>::tree(const Myt& x)
		: Mybase(x.key_comp(), x.get_allocator()) {
	Init();
	Copy(x);
}

template<class T>
tree<T>::~tree() {
	erase(begin(), end());
	Freenode(Head);
	Head = 0;
	Size = 0;
}

template<class T>
typename tree<T>::Myt& tree<T>::operator=(const Myt& x) {
	if (this != &x) {
		erase(begin(), end());
		comp = x.comp;
		Copy(x);
	}
	return (*this);
}

template<class T>
typename tree<T>::allocator_type tree<T>::get_allocator() const;
	return (Alval);
}

#endif //FT_CONTAINERS_TREE_CONSTRUCTORS_HPP
