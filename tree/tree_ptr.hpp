#ifndef FT_CONTAINERS_TREE_PTR_HPP
#define FT_CONTAINERS_TREE_PTR_HPP

#include "tree_nod.hpp"

namespace ft {

template<class T>
class tree_ptr : public tree_nod<T> {

	protected:
		typedef typename tree_nod<T>::node		node;
		typedef typename T::allocator_type		allocator_type;
		typedef typename T::key_compare			key_compare;
		typedef typename allocator_type::template
				rebind<node>::other::poiner		nodeptr;

		tree_ptr(const key_compare& parg, allocator_type Al)
				: tree_nod<T>(parg, Al), Alptr(Al) {}

		typename allocator_type::template
				rebind<nodeptr>::other			Alptr;

};

}

#endif //FT_CONTAINERS_TREE_PTR_HPP
