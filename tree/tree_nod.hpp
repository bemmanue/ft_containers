#ifndef FT_CONTAINERS_TREE_NOD_HPP
#define FT_CONTAINERS_TREE_NOD_HPP

namespace ft {

template <class Tree_traits>
class tree_nod : public Tree_traits {

	protected:
		typedef typename Tree_traits::allocator_type		allocator_type;
		typedef typename Tree_traits::key_compare			key_compare;
		typedef typename Tree_traits::value_type			value_type;
		typedef typename allocator_type::template
				rebind<void>::other::pointer 				genptr;

		struct node;
		friend struct node;
		struct node {
			genptr		left;
			genptr		parent;
			genptr		right;
			value_type	value;
			char		color;
			char		isnil;
		};

		tree_nod(const key_compare& parg, allocator_type Al)
				: Tree_traits(parg), Alnod(Al) {}

		typename allocator_type::template
				rebind<node>::other							Alnod;

};

}

#endif //FT_CONTAINERS_TREE_NOD_HPP
