#ifndef TREE_ITERATORS_HPP
#define TREE_ITERATORS_HPP

#include "tree_base.hpp"

namespace ft {

template<class Tree_traits>
typename tree<Tree_traits>::iterator tree<Tree_traits>::begin() {
	return iterator(Lmost());
}

template<class Tree_traits>
typename tree<Tree_traits>::const_iterator tree<Tree_traits>::begin() const {
	return const_iterator(Lmost());
}

template<class Tree_traits>
typename tree<Tree_traits>::iterator tree<Tree_traits>::end() {
	return iterator(Head);
}

template<class Tree_traits>
typename tree<Tree_traits>::const_iterator tree<Tree_traits>::end() const {
	return const_iterator(Head);
}

template<class Tree_traits>
typename tree<Tree_traits>::reverse_iterator tree<Tree_traits>::rbegin() {
	return reverse_iterator(end());
}

template<class Tree_traits>
typename tree<Tree_traits>::const_reverse_iterator tree<Tree_traits>::rbegin() const {
	return const_reverse_iterator(end());
}

template<class Tree_traits>
typename tree<Tree_traits>::reverse_iterator tree<Tree_traits>::rend() {
	return reverse_iterator(begin());
}

template<class Tree_traits>
typename tree<Tree_traits>::const_reverse_iterator tree<Tree_traits>::rend() const {
	return const_reverse_iterator(begin());
}

}

#endif //TREE_ITERATORS_HPP
