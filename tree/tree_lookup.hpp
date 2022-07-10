#ifndef FT_CONTAINERS_TREE_LOOKUP_HPP
#define FT_CONTAINERS_TREE_LOOKUP_HPP

#include "tree.hpp"

namespace ft {

template<class T>
typename tree<T>::size_type tree<T>::count(const key_type& Kv) const {
	paircc Ans = equal_range(Kv);
	size_type N = 0;
	Distance(Ans.first, Ans.second, N);
	return (N);
}

template<class T>
typename tree<T>::tree_iterator tree<T>::find(const key_type& Kv) {
	tree_iterator P = lower_bound(Kv);
	return (P == end() || comp(Kv, Key(P.mynode())) ? end() : P);
}

template<class T>
typename tree<T>::tree_const_iterator tree<T>::find(const key_type& Kv) const {
	const_tree_iterator P = lower_bound(Kv);
	return (P == end() || comp(Kv, Key(P.mynode())) ? end() : P);
}

template<class T>
typename tree<T>::pairii tree<T>::equal_range(const key_type& Kv) {
	return (pairii(lower_bound(Kv), upper_bound(Kv)));
}

template<class T>
typename tree<T>::paircc tree<T>::equal_range(const key_type& Kv) const {
	return (paircc(lower_bound(Kv), upper_bound(Kv)));
}

template<class T>
typename tree<T>::tree_iterator tree<T>::lower_bound(const key_type& Kv) {
	return (tree_iterator(Lbound(Kv)));
}

template<class T>
typename tree<T>::tree_const_iterator tree<T>::lower_bound(const key_type& Kv) const {
	return (const_tree_iterator(Lbound(Kv)));
}

template<class T>
typename tree<T>::tree_iterator tree<T>::upper_bound(const key_type& Kv) {
	return (tree_iterator(Ubound(Kv)));
}

template<class T>
typename tree<T>::tree_const_iterator tree<T>::upper_bound(const key_type& Kv) const {
	return (const_tree_iterator(Ubound(Kv)));
}

template<class T>
void tree<T>::swap(Myt& x) {
	if (get_allocator() == x.get_allocator()) {
		std::swap(comp, x.comp);
		std::swap(Head, x.Head);
		std::swap(Size, x.Size);
	} else {
		Myt Ts = *this;
		*this = x;
		x = Ts;
	}
}

}


#endif //FT_CONTAINERS_TREE_LOOKUP_HPP
