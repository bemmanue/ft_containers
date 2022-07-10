#ifndef FT_CONTAINERS_TREE_VALUE_HPP
#define FT_CONTAINERS_TREE_VALUE_HPP

#include "tree.hpp"

namespace ft {

template<class Tree_traits>
class tree_value : public tree_ptr<Tree_traits> {

	protected:
		typedef typename Tree_traits::allocator_type		allocator_type;
		typedef typename Tree_traits::key_compare			key_compare;

		tree_value(const key_compare& parg, allocator_type Al)
				: tree_ptr<Tree_traits>(parg, Al), Alval(Al) {}

		allocator_type	Alval;
};

}

#endif //FT_CONTAINERS_TREE_VALUE_HPP
