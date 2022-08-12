#ifndef TREE_OPERATORS_HPP
#define TREE_OPERATORS_HPP

#include "tree_base.hpp"
#include "../algorithm/algorithm.hpp"

namespace ft {

template<class Tree_traits> inline
void swap(tree<Tree_traits>& lhs, tree<Tree_traits>& rhs) {
	lhs.swap(rhs);
}

template<class Tree_traits> inline
bool operator==(const tree<Tree_traits>& lhs, const tree<Tree_traits>& rhs) {
	return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class Tree_traits> inline
bool operator!=(const tree<Tree_traits>& lhs, const tree<Tree_traits>& rhs) {
	return !(lhs == rhs);
}

template<class Tree_traits> inline
bool operator<(const tree<Tree_traits>& lhs, const tree<Tree_traits>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), lhs.value_comp());
}

template<class Tree_traits> inline
bool operator>(const tree<Tree_traits>& lhs, const tree<Tree_traits>& rhs) {
	return rhs < lhs;
}

template<class Tree_traits> inline
bool operator<=(const tree<Tree_traits>& lhs, const tree<Tree_traits>& rhs) {
	return !(rhs < lhs);
}

template<class Tree_traits> inline
bool operator>=(const tree<Tree_traits>& lhs, const tree<Tree_traits>& rhs) {
	return !(lhs < rhs);
}

}

#endif //TREE_OPERATORS_HPP
