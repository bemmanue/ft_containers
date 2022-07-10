#ifndef FT_CONTAINERS_TREE_PROTECTED_HPP
#define FT_CONTAINERS_TREE_PROTECTED_HPP

#include "tree.hpp"

namespace ft {

template<class T>
void tree<T>::Copy(const Myt& x) {
	Root() = Copy(x.Root(), Head);
	Size = x.size();
	if (!isnil(Root())) {
		Lmost() = Min(Root());
		Rmost() = Max(Root());
	} else {
		Lmost() = Head, Rmost() = Head();
	}
}

template<class T>
typename tree<T>::nodeptr tree<T>::Copy(nodeptr x, nodeptr p) {
	nodeptr R = Head;
	if (!Isnil(x)) {
		nodeptr y = Buynode(p, Color(x));
		try {
			Consval(&value(y), value(x));
		} catch(...) {
			Freenode(y);
			Erase(R);
			throw;
		}
		left(y) = Head, right(y) = Head;
		if (isnil(R)) {
			R = y;
		}
		try {
			left(y) = Copy(left(x), y);
			right(y) = Copy(right(x), y);
		} catch (...) {
			Erase(R);
			throw;
		}
	}
	return (R);
}

template<class T>
void tree<T>::Erase(nodeptr x) {
	for (nodeptr y = x; !isnil(y); x = y) {
		Erase(right(y));
		y = left(y);
		Destval(&value(x));
		Freenode(x);
	}
}

template<class T>
void tree<T>::Init() {
	Head = Buynode(0, Black);
	isnil(Head) = true;
	Root() = Head;
	Lmost() = Head, Rmost() = Head;
	Size = 0;
}

template<class T>
typename tree<T>::tree_iterator tree<T>::Insert(bool Addleft, nodeptr Y, const value_type& v) {
	if (max_size() - 1 <= Size)
		throw std::length_error("map/set<T> too long");
	nodeptr Z = Buynode(Y, Red);    //create new node that we insert. Y is considered its parent node
	Left(Z) = Head, Right(Z) = Head;
	try {
		Consval(&Value(Z), v); //initialize its value
	} catch (...) {
		Freenode(Z);
		throw;
	}
	++Size;
	if (Y == Head) {
		Root() = Z;
		Lmost() = Z, Rmost() = Z;
	} else if (Addleft) //check whether to add it to the left of node Y or not
		{
		Left(Y) = Z;
		if (Y == Lmost())
			Lmost() = Z;
		} else {
		Right(Y) = Z;
		if (Y == Rmost())
			Rmost() = Z;
	}
	for (nodeptr X = Z; Color(Parent(X)) == Red;) //check that we didn't disbalance our tree
		{
		if (Parent(X) == Left(Parent(Parent(X)))) {
			Y = Right(Parent(Parent(X)));
			if (Color(Y) == Red) {
				Color(Parent(X)) = Black;
				Color(Y) = Black;
				Color(Parent(Parent(X))) = Red;
				X = Parent(Parent(X));
			} else {
				if (X == Right(Parent(X))) {
					X = Parent(X);
					Lrotate(X);
				}
				Color(Parent(X)) = Black;
				Color(Parent(Parent(X))) = Red;
				Rrotate(Parent(Parent(X)));
			}
		} else {
			Y = Left(Parent(Parent(X))); // 1
			if (Color(Y) == Red) {
				Color(Parent(X)) = Black;
				Color(Y) = Black;
				Color(Parent(Parent(X))) = Red;
				X = Parent(Parent(X));
			} else {
				if (X == Left(Parent(X))) {
					X = Parent(X);
					Rrotate(X);
				}
				Color(Parent(X)) = Black; // 2
				Color(Parent(Parent(X))) = Red; // 3
				Lrotate(Parent(Parent(X))); // 4
			}
		}
		}
	Color(Root()) = Black;
	return tree_iterator(Z);
}

template<class T>
typename tree<T>::nodeptr tree<T>::Lbound(const key_type& Kv) const {
	nodeptr X = Root();
	nodeptr Y = Head;
	while (!(Isnil(X)))
	{
		if (T::comp(Key(X), Kv))
			X = Right(X);
		else
			Y = X, X = Left(X);
	}
	return (Y);
}

template<class T>
typename tree<T>::nodeptr& tree<T>::Lmost() {
	return Left(Head);
}

template<class T>
typename tree<T>::nodeptr& tree<T>::Lmost() const {
	return (Left(Head));
}

template<class T>
void tree<T>::Lrotate(nodeptr X) {
	nodeptr Y = Right(X);
	Right(X) = Left(Y);
	if (!Isnil(Left(Y)))
		Parent(Left(Y)) = X;
	Parent(Y) = Parent(X);
	if (X == Root())
		Root() = Y;
	else if (X == Left(Parent(X)))
		Left(Parent(X)) = Y;
	else
		Right(Parent(X)) = Y;
	Left(Y) = X;
	Parent(X) = Y;
}

template<class T>
typename tree<T>::nodeptr tree<T>::Max(nodeptr P) {
	while (!Isnil(Right(P)))
		P = Right(P);
	return P;
}

template<class T>
typename tree<T>::nodeptr tree<T>::Min(nodeptr P) {
	while (!Isnil(Left(P)))
		P = Left(P);
	return P;
}

template<class T>
typename tree<T>::nodeptr& tree<T>::Rmost() {
	return Right(Head);
}

template<class T>
typename tree<T>::nodeptr& tree<T>::Rmost() const {
	return Right(Head);
}

template<class T>
typename tree<T>::nodeptr& tree<T>::Root() {
	return Parent(Head);
}

template<class T>
typename tree<T>::nodeptr& tree<T>::Root() const {
	return Parent(Head);
}

template<class T>
void tree<T>::Rrotate(nodeptr X) {
	nodeptr Y = Left(X);
	Left(X) = Right(Y);
	if (!Isnil(Right(Y)))
		Parent(Right(Y)) = X;
	Parent(Y) = Parent(X);
	if (X == Root())
		Root() = Y;
	else if (X == Right(Parent(X)))
		Right(Parent(X)) = Y;
	else
		Left(Parent(X)) = Y;
	Right(Y) = X;
	Parent(X) = Y;
}

template<class T>
typename tree<T>::nodeptr tree<T>::Ubound(const key_type& Kv) const {
	nodeptr X = Root();
	nodeptr Y = Head;
	while (!Isnil(X))
	{
		if (T::comp(Kv, Key(X)))
			Y = X, X = Left(X);
		else
			X = Right(X);
	}
	return Y;
}

template<class T>
typename tree<T>::nodeptr tree<T>::Buynode(nodeptr parg, char Carg) {
	nodeptr S = this->Alnod.allocate(1);
	this->Alptr.construct(&Left(S), nullptr);
	this->Alptr.construct(&Right(S), nullptr);
	this->Alptr.construct(&Parent(S), parg);
	Color(S) = Carg;
	Isnil(S) = false;
	return S;
}

template<class T>
void tree<T>::Consval(tptr P, const value_type& V) {
	this->Alval.construct(P, V);
}

template<class T>
void tree<T>::Destval(tptr P) {
	this->Alval.destroy(P);
}

template<class T>
void tree<T>::Freenode(nodeptr S) {
	this->Alptr.destroy(&Parent(S));
	this->Alptr.destroy(&Right(S));
	this->Alptr.destroy(&Left(S));
	this->Alnod.deallocate(S, 1);
}

}


#endif //FT_CONTAINERS_TREE_PROTECTED_HPP
