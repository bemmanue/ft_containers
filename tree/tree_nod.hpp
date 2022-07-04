#ifndef FT_CONTAINERS_TREE_NOD_HPP
#define FT_CONTAINERS_TREE_NOD_HPP

namespace ft {

template <class T>
class tree_nod : public T {

	protected:
		typedef typename T::allocator_type			allocator_type;
		typedef typename T::key_compare				key_compare;
		typedef typename T::value_type				value_type;
		typedef typename allocator_type::template
				rebind<void>::other::pointer 		genptr;

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
				: T(parg), Alnod(Al) {}

		typename allocator_type::template
				rebind<node>::other					Alnod;

};

}

#endif //FT_CONTAINERS_TREE_NOD_HPP
