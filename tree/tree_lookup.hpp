#ifndef TREE_LOOKUP_HPP
#define TREE_LOOKUP_HPP

#include "tree_base.hpp"

namespace ft {

template<class Tree_traits>
typename tree<Tree_traits>::size_type tree<Tree_traits>::count(const key_type& Kv) const {
	Paircc Ans = equal_range(Kv);
	size_type n = 0;
	Distance(Ans.first, Ans.second, n);
	return n;
}

template<class Tree_traits>
typename tree<Tree_traits>::iterator tree<Tree_traits>::find(const key_type& Kv) {
	iterator P = lower_bound(Kv);
	return (P == end() || this->comp(Kv, Key(P.Mynode())) ? end() : P);
}

template<class Tree_traits>
typename tree<Tree_traits>::const_iterator tree<Tree_traits>::find(const key_type& Kv) const {
	const_iterator P = lower_bound(Kv);
	return (P == end() || this->comp(Kv, Key(P.Mynode())) ? end() : P);
}

template<class Tree_traits>
typename tree<Tree_traits>::Pairii tree<Tree_traits>::equal_range(const key_type& Kv) {
	return Pairii(lower_bound(Kv), upper_bound(Kv));
}

template<class Tree_traits>
typename tree<Tree_traits>::Paircc tree<Tree_traits>::equal_range(const key_type& Kv) const {
	return Paircc(lower_bound(Kv), upper_bound(Kv));
}

template<class Tree_traits>
typename tree<Tree_traits>::iterator tree<Tree_traits>::lower_bound(const key_type& Kv) {
	return iterator(Lbound(Kv));
}

template<class Tree_traits>
typename tree<Tree_traits>::const_iterator tree<Tree_traits>::lower_bound(const key_type& Kv) const {
	return const_iterator(Lbound(Kv));
}

template<class Tree_traits>
typename tree<Tree_traits>::iterator tree<Tree_traits>::upper_bound(const key_type& Kv) {
	return iterator(Ubound(Kv));
}

template<class Tree_traits>
typename tree<Tree_traits>::const_iterator tree<Tree_traits>::upper_bound(const key_type& Kv) const {
	return const_iterator(Ubound(Kv));
}

template<class Tree_traits>
void tree<Tree_traits>::swap(Myt& x) {
	if (get_allocator() == x.get_allocator()) {
		std::swap(Tree_traits::comp, x.comp);
		std::swap(Head, x.Head);
		std::swap(Size, x.Size);
	} else {
		Myt temp = *this;
		*this = x;
		x = temp;
	}
}

}

#endif //TREE_LOOKUP_HPP
