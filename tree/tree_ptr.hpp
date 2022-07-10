#ifndef FT_CONTAINERS_TREE_PTR_HPP
#define FT_CONTAINERS_TREE_PTR_HPP

#include "tree.hpp"

namespace ft {

template<class Tree_traits>
class tree_ptr : public tree_nod<Tree_traits> {

	protected:
		typedef typename tree_nod<Tree_traits>::node		node;
		typedef typename Tree_traits::allocator_type		allocator_type;
		typedef typename Tree_traits::key_compare			key_compare;
		typedef typename allocator_type::template
				rebind<node>::other::poiner					nodeptr;

		tree_ptr(const key_compare& parg, allocator_type Al)
				: tree_nod<Tree_traits>(parg, Al), Alptr(Al) {}

		typename allocator_type::template
				rebind<nodeptr>::other						Alptr;

};

}

#endif //FT_CONTAINERS_TREE_PTR_HPP
