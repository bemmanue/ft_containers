#ifndef TREE_CONSTRUCTORS_HPP
#define TREE_CONSTRUCTORS_HPP

#include "tree_base.hpp"

namespace ft {

template<class Tree_traits>
tree<Tree_traits>::tree(const key_compare& parg, const allocator_type& Al)
		: Mybase(parg, Al) {
	Init();
}

template <class Tree_traits>
tree<Tree_traits>::tree(const value_type* F, const value_type* L, const key_compare& parg, const allocator_type& Al)
		: Mybase(parg, Al) {
	Init();
	insert(F, L);
}

template<class Tree_traits>
tree<Tree_traits>::tree(const Myt& x)
		: Mybase(x.key_comp(), x.get_allocator()) {
	Init();
	Copy(x);
}

template<class Tree_traits>
tree<Tree_traits>::~tree() {
	erase(begin(), end());
	Freenode(Head);
	Head = 0;
	Size = 0;
}

template<class Tree_traits>
typename tree<Tree_traits>::Myt& tree<Tree_traits>::operator=(const Myt& x) {
	if (this != &x) {
		erase(begin(), end());
		Tree_traits::comp = x.comp;
		Copy(x);
	}
	return *this;
}

template<class Tree_traits>
typename tree<Tree_traits>::allocator_type tree<Tree_traits>::get_allocator() const {
	return this->Alval;
}

}
#endif //TREE_CONSTRUCTORS_HPP
