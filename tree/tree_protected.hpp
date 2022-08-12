#ifndef TREE_PROTECTED_HPP
#define TREE_PROTECTED_HPP

#include "tree_base.hpp"

namespace ft {

template<class Tree_traits>
void tree<Tree_traits>::Copy(const Myt& x) {
	Root() = Copy(x.Root(), Head);
	Size = x.size();

	if (!Isnil(Root())) {
		Lmost() = Min(Root());
		Rmost() = Max(Root());
	} else {
		Lmost() = Head;
		Rmost() = Head;
	}
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr tree<Tree_traits>::Copy(Nodeptr x, Nodeptr p) {
	Nodeptr R = Head;
	if (!Isnil(x)) {
		Nodeptr y = Buynode(p, Color(x));
		try {
			Consval(&Value(y), Value(x));
		} catch(...) {
			Freenode(y);
			Erase(R);
			throw;
		}
		Left(y) = Head, Right(y) = Head;
		if (Isnil(R)) {
			R = y;
		}
		try {
			Left(y) = Copy(Left(x), y);
			Right(y) = Copy(Right(x), y);
		} catch (...) {
			Erase(R);
			throw;
		}
	}
	return R;
}

template<class Tree_traits>
void tree<Tree_traits>::Erase(Nodeptr x) {
	for (Nodeptr y = x; !Isnil(y); x = y) {
		Erase(Right(y));
		y = Left(y);
		Destval(&Value(x));
		Freenode(x);
	}
}

template<class Tree_traits>
void tree<Tree_traits>::Init() {
	Head = Buynode(0, Black);
	Isnil(Head) = true;
	Root() = Head;
	Lmost() = Head, Rmost() = Head;
	Size = 0;
}

template<class Tree_traits>
typename tree<Tree_traits>::iterator tree<Tree_traits>::Insert(bool Addleft, Nodeptr Y, const value_type& v) {
	if (max_size() - 1 <= Size)
		throw std::length_error("map/set<Tree_traits> too long");
	Nodeptr Z = Buynode(Y, Red);
	Left(Z) = Head, Right(Z) = Head;
	try {
		Consval(&Value(Z), v);
	} catch (...) {
		Freenode(Z);
		throw;
	}
	++Size;
	if (Y == Head) {
		Root() = Z;
		Lmost() = Z, Rmost() = Z;
	} else if (Addleft)
		{
		Left(Y) = Z;
		if (Y == Lmost())
			Lmost() = Z;
		} else {
		Right(Y) = Z;
		if (Y == Rmost())
			Rmost() = Z;
	}
	for (Nodeptr X = Z; Color(Parent(X)) == Red; )
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
			Y = Left(Parent(Parent(X)));
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
				Color(Parent(X)) = Black;
				Color(Parent(Parent(X))) = Red;
				Lrotate(Parent(Parent(X)));
			}
		}
		}
	Color(Root()) = Black;
	return iterator(Z);
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr tree<Tree_traits>::Lbound(const key_type& Kv) const {
	Nodeptr X = Root();
	Nodeptr Y = Head;
	while (!(Isnil(X)))
	{
		if (Tree_traits::comp(Key(X), Kv))
			X = Right(X);
		else
			Y = X, X = Left(X);
	}
	return (Y);
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr& tree<Tree_traits>::Lmost() {
	return Left(Head);
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr& tree<Tree_traits>::Lmost() const {
	return (Left(Head));
}

template<class Tree_traits>
void tree<Tree_traits>::Lrotate(Nodeptr X) {
	Nodeptr Y = Right(X);
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

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr tree<Tree_traits>::Max(Nodeptr P) {
	while (!Isnil(Right(P)))
		P = Right(P);
	return P;
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr tree<Tree_traits>::Min(Nodeptr P) {
	while (!Isnil(Left(P)))
		P = Left(P);
	return P;
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr& tree<Tree_traits>::Rmost() {
	return Right(Head);
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr& tree<Tree_traits>::Rmost() const {
	return Right(Head);
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr& tree<Tree_traits>::Root() {
	return Parent(Head);
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr& tree<Tree_traits>::Root() const {
	return Parent(Head);
}

template<class Tree_traits>
void tree<Tree_traits>::Rrotate(Nodeptr X) {
	Nodeptr Y = Left(X);
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

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr tree<Tree_traits>::Ubound(const key_type& Kv) const {
	Nodeptr X = Root();
	Nodeptr Y = Head;
	while (!Isnil(X))
	{
		if (Tree_traits::comp(Kv, Key(X)))
			Y = X, X = Left(X);
		else
			X = Right(X);
	}
	return Y;
}

template<class Tree_traits>
typename tree<Tree_traits>::Nodeptr tree<Tree_traits>::Buynode(Nodeptr parg, char Carg) {
	Nodeptr S = this->Alnod.allocate(1);
	this->Alptr.construct(&Left(S));
	this->Alptr.construct(&Right(S));
	this->Alptr.construct(&Parent(S), parg);
	Color(S) = Carg;
	Isnil(S) = false;
	return S;
}

template<class Tree_traits>
void tree<Tree_traits>::Consval(pointer P, const value_type& V) {
	this->Alval.construct(P, V);
}

template<class Tree_traits>
void tree<Tree_traits>::Destval(pointer P) {
	this->Alval.destroy(P);
}

template<class Tree_traits>
void tree<Tree_traits>::Freenode(Nodeptr S) {
	this->Alptr.destroy(&Parent(S));
	this->Alptr.destroy(&Right(S));
	this->Alptr.destroy(&Left(S));
	this->Alnod.deallocate(S, 1);
}

}


#endif //TREE_PROTECTED_HPP
