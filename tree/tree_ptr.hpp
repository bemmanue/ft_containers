#ifndef TREE_PTR_HPP
#define TREE_PTR_HPP

#include "tree_node.hpp"

namespace ft {

template<class Tree_traits>
class tree_ptr : public ft::tree_node<Tree_traits> {

	protected:
		typedef typename tree_node<Tree_traits>::Node		Node;
		typedef typename Tree_traits::allocator_type		allocator_type;
		typedef typename Tree_traits::key_compare			key_compare;
		typedef typename allocator_type::template
				rebind<Node>::other::pointer				nodeptr;

		tree_ptr(const key_compare& parg, allocator_type Al)
				: tree_node<Tree_traits>(parg, Al), Alptr(Al) {}

		typename allocator_type::template
				rebind<nodeptr>::other						Alptr;

};

}

#endif //TREE_PTR_HPP
