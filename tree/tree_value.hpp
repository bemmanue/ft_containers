#ifndef FT_CONTAINERS_TREE_VALUE_HPP
#define FT_CONTAINERS_TREE_VALUE_HPP

#include "tree_ptr.hpp"

namespace ft {

template<class T>
class tree_value : public tree_ptr<T> {

	protected:
		typedef typename T::allocator_type		allocator_type;
		typedef typename T::key_compare			key_compare;

		tree_value(const key_compare& parg, allocator_type Al)
				: tree_ptr<T>(parg, Al), Alval(Al) {}

		allocator_type	Alval;
};

}

#endif //FT_CONTAINERS_TREE_VALUE_HPP
