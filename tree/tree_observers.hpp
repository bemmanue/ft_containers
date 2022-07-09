#ifndef FT_CONTAINERS_TREE_OBSERVERS_HPP
#define FT_CONTAINERS_TREE_OBSERVERS_HPP

#include "tree.hpp"

namespace ft {

template<class Tree_traits>
typename tree<Tree_traits>::key_compare tree<Tree_traits>::key_comp() const {
	return (comp);
}

template<class Tree_traits>
typename tree<Tree_traits>::value_compare tree<Tree_traits>::value_comp() const {
	return (value_compare(key_comp()));
}

}

#endif //FT_CONTAINERS_TREE_OBSERVERS_HPP
