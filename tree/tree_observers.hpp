#ifndef TREE_OBSERVERS_HPP
#define TREE_OBSERVERS_HPP

#include "tree_base.hpp"

namespace ft {

template<class Tree_traits>
typename tree<Tree_traits>::key_compare tree<Tree_traits>::key_comp() const {
	return (Tree_traits::comp);
}

template<class Tree_traits>
typename tree<Tree_traits>::value_compare tree<Tree_traits>::value_comp() const {
	return (value_compare(key_comp()));
}

}

#endif //TREE_OBSERVERS_HPP
