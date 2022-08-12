#ifndef TREE_NOD_HPP
#define TREE_NOD_HPP

namespace ft {

template <class Tree_traits>
class tree_node : public Tree_traits {

	protected:
		typedef typename Tree_traits::allocator_type		allocator_type;
		typedef typename Tree_traits::key_compare			key_compare;
		typedef typename Tree_traits::value_type			value_type;
		typedef typename allocator_type::template
				rebind<void>::other::pointer 				Genptr;

		struct Node;
		friend struct Node;
		struct Node {
			Genptr		Left;
			Genptr		Parent;
			Genptr		Right;
			value_type	Value;
			char		Color;
			char		Isnil;
		};

		tree_node(const key_compare& parg, allocator_type Al)
				: Tree_traits(parg), Alnod(Al) {}

		typename allocator_type::template
				rebind<Node>::other							Alnod;

};

}

#endif //TREE_NOD_HPP
