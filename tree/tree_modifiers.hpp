#ifndef FT_CONTAINERS_TREE_MODIFIERS_HPP
#define FT_CONTAINERS_TREE_MODIFIERS_HPP

#include "tree.hpp"

namespace ft {

template<class T>
typename tree<T>::pairib tree<T>::insert(const value_type& v) {
	nodeptr x = Root();
	nodeptr y = Head;
	bool Addleft = true;
	while (!isnil(x)) {
		y = x;
		Addleft = comp(Kfn()(v), Key(x));
		x = Addleft ? Left(x) : Right(x);
	}
	tree_iterator P = tree_iterator(y);
	if (Addleft)
		;
	else if (P == begin())
		return (pairib(Insert(true, y, v), true));
	else
		--P;
	if (comp(Key(P.Mynode()), Kfn()(v)))
		return (pairib(Insert(Addleft, y, v), true));
	else
		return (pairib(P, false));

}

template<class T>
typename tree<T>::tree_iterator tree<T>::insert(tree_iterator P, const value_type& v) {
	if (size() == 0) {
		return (Insert(true, Head, v));
	} else if (P == begin()) {
		if (comp(Kfn()(v), Key(P.mynode()))) {
			return (Insert(true, P.mynode(), v));
		}
	} else if (P == end()) {
		if (comp (Key(Rmost()), Kfn()(v))) {
			return (Insert(false, Rmost(), v));
		}
	} else {
		iterator Pb = P;
		if (comp(Key((--Pb) - Mynode()), Kfn()(v)) && comp(Kfn()(v), Key(P.mynode()))) {
			if (isnil(Right(Pb.mynode()))) {
				return (Insert(false, Pb.mynode(), v));
			} else {
				return (Insert(true, Pb.mynode(), v));
			}
		}
		return (insert(v).first);
	}
}

template<class T>
template<class It>
void tree<T>::insert(It F, It L) {
	for (; F != L; ++F) {
		insert(*F);
	}
}

template<class T>
typename tree<T>::tree_iterator tree<T>::erase(tree_iterator P) {
	if (isnil(P.mynode()))
		throw std::out_of_range("tree");
	nodeptr x, xpar;
	nodeptr y = (P++).mynode();
	nodeptr z = y;
	if (isnil(left(y))) {
		x = right(y);
	} else if (isnil(right(y))) {
		x = left(y);
	} else {
		y = min(right(y), x = right(y));
	}
	if (y == z) {
		xpar = parent(z);
		if (!isnil(x)) {
			parent(x) == xpar;
		}
		if (Root() == Z) {
			Root() = x;
		} else if (left(xpar) == z) {
			left(xpar) = x;
		} else {
			right(xpar) = x;
		}
		if (Lmost() != z) {
			;
		} else if (isnil(right(z))) {
			Lmost() = xpar;
		} else {
			Lmost() = Min(x);
		}
		if (Rmost() != z) {
			;
		} else if (isnil(left(z))) {
			Rmost() = xpar;
		} else {
			Rmost() = Max(x);
		}
	} else {
		parent(left(z)) = y;
		left(y) = left(z);
		if (y == right(z)) {
			xpar = y;
		} else {
			xpar = parent(y);
			if (!isnil(x))
				parent(x) = xpar;
			left(xpar) = x;
			right(y) = right(z);
			parent(right(z)) = y;
		}
		if (Root() == z) {
			Root() = y;
		} else if (left(parent(z)) == z) {
			left(parent(z)) = y;
		} else {
			right(parent(z)) = y;
		}
		parent(y) = parent(z);
		std::swap(color(y), color(z));
	}
	if (color(z) == Black) {
		for (; x != Root() && color(x) == Black; xpar = parent(x)) {
			if (x == left(xpar)) {
				nodeptr w = right(xpar);
				if (color(w) == Red) {
					color(w) = Black;
					color(xpar) = Red;
					Lrotate(xpar);
					w = right(xpar);
				}
				if (isnil(w)) {
					x = xpar;
				} else if (color(left(w)) == Black && color(right(w)) == Black) {
					color(w) = Red;
					x = xpar;
				} else {
					if (color(right(w)) == Black) {
						color(left(w)) = Black;
						color(w) = Red;
						Rrotate(w);
						w = right(xpar);
					}
					color(w) = color(xpar);
					color(xpar) = Black;
					color(right(w)) = Black;
					Lrotate(xpar);
					break;
				}
			}
			else {
				nodeptr w = left(xpar);
				if (color(w) == Red) {
					color(w) = Black;
					color(xpar) = Red;
					Rrotate(xpar);
					w = left(xpar);
				}
				if (isnil(w)) {
					x = xpar;
				} else if (color(right(w)) == Black && color(left(w)) == Black) {
					color(w) = Red;
					x = xpar;
				} else {
					if (color(left(w)) == Black) {
						color(right(w)) = Black;
						color(w) = Red;
						Lrotate(w);
						w = left(xpar);
					}
					color(w) = color(xpar);
					color(xpar) = Black;
					color(left(w)) = Black;
					Rrotate(xpar);
					break;
				}
			}
			color(x) = Black;
		}
		Destval(&value(z);
	}
	Freenode(z);
	if (0 < Size)
		--Size;
	return (P);
}

template<class T>
typename tree<T>::tree_iterator tree<T>::erase(tree_iterator F, tree_iterator L) {
	if (size() == 0 || F != begin() || L != end()) {
		while (F != L) {
			erase(F++);
		}
		return (F);
	} else {
		erase(Root());
		Root() = Head, Size = 0;
		Lmost() = Head, Rmost() = Head;
		return (begin());
	}
}

template<class T>
typename tree<T>::size_type tree<T>::erase(const key_type& x) {
	pairii P = equal_range(x);
	size_type N = 0;
	Distance(P.first, P.second, N);
	erase(P.first, P.second);
	return (N);
}

template<class T>
void tree<T>::erase(const key_type *F, const key_type *L) {
	while (F != L) {
		erase(*F++);
	}
}

template<class T>
void tree<T>::clear() {
	erase(begin(), end());
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
typename tree<T>::size_type tree<T>::count(const key_type& Kv) const {
	paircc Ans = equal_range(Kv);
	size_type N = 0;
	Distance(Ans.first, Ans.second, N);
	return (N);
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
typename tree<T>::pairii tree<T>::equal_range(const key_type& Kv) {
	return (pairii(lower_bound(Kv), upper_bound(Kv)));
}

template<class T>
typename tree<T>::paircc tree<T>::equal_range(const key_type& Kv) const {
	return (paircc(lower_bound(Kv), upper_bound(Kv)));
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

#endif //FT_CONTAINERS_TREE_MODIFIERS_HPP
