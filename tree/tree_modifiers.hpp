#ifndef TREE_MODIFIERS_HPP
#define TREE_MODIFIERS_HPP

#include "tree_base.hpp"

namespace ft {

template<class Tree_traits>
typename tree<Tree_traits>::Pairib tree<Tree_traits>::insert(const value_type& v) {
	Nodeptr	X = Root();
	Nodeptr	Y = Head;
	bool	Addleft = true;

	while (!Isnil(X))
	{
		Y = X;
		Addleft = Tree_traits::comp(Tree_traits::GetKey(v), Key(X));
		X = Addleft ? Left(X) : Right(X);
	}
	iterator P = iterator(Y);
	if (!Addleft) {
		;
	} else if (P == begin()) {
		return Pairib(Insert(true, Y, v), true);
	} else {
		--P;
	}
	if (Tree_traits::comp(Key(P.Mynode()), Tree_traits::GetKey(v))) {
		return (Pairib(Insert(Addleft, Y, v), true));
	} else {
		return (Pairib(P, false));
	}
}

template<class Tree_traits>
typename tree<Tree_traits>::iterator tree<Tree_traits>::insert(iterator P, const value_type& v) {
	if (size() == 0) {
		return Insert(true, Head, v);
	} else if (P == begin()) {
		if (Tree_traits::comp(Tree_traits::GetKey(v), Key(P.Mynode())))
			return Insert(false, Rmost(), v);
	} else {
		iterator Pb = P;
		if (Tree_traits::comp(Key((--Pb).Mynode()), Tree_traits::GetKey(v))
			&& Tree_traits::comp(Tree_traits::GetKey(v), Key(P.Mynode())))
		{
			if (Isnil(Right(Pb.Mynode())))
				return Insert(false, Pb.Mynode(), v);
			else
				return Insert(true, P.Mynode(), v);
		}
	}
	return insert(v).first;
}

template<class Tree_traits>
template<class It>
void tree<Tree_traits>::insert(It F, It L) {
	for (; F != L; ++F) {
		insert(*F);
	}
}

template<class Tree_traits>
typename tree<Tree_traits>::iterator tree<Tree_traits>::erase(iterator P) {
	if (Isnil(P.Mynode()))
		throw std::out_of_range("map/set<T> iterator");
	Nodeptr X;
	Nodeptr Xpar;
	Nodeptr Y = (P++).Mynode();
	Nodeptr	Z = Y;
	if (Isnil(Left(Y)))
		X = Right(Y);
	else if (Isnil(Right(Y)))
		X = Left(Y);
	else
		Y = Min(Right(Y)), X = Right(Y);
	if (Y == Z)
	{
		Xpar = Parent(Z);
		if (!Isnil(X))
			Parent(X) = Xpar;
		if (Root() == Z)
			Root() = X;
		else if (Left(Xpar) == Z)
			Left(Xpar) = X;
		else
			Right(Xpar) = X;
		if (Lmost() != Z)
			;
		else if (Isnil(Right(Z)))
			Lmost() = Xpar;
		else
			Lmost() = Min(X);
		if (Rmost() != Z)
			;
		else if (Isnil(Left(Z)))
			Rmost() = Xpar;
		else
			Rmost() = Max(X);
	}
	else
	{
		Parent(Left(Z)) = Y;
		Left(Y) = Left(Z);
		if (Y == Right(Z))
			Xpar = Y;
		else
		{
			Xpar = Parent(Y);
			if (!Isnil(X))
				Parent(X) = Xpar;
			Left(Xpar) = X;
			Right(Y) = Right(Z);
			Parent(Right(Z)) = Y;
		}
		if (Root() == Z)
			Root() = Y;
		else if (Left(Parent(Z)) == Z)
			Left(Parent(Z)) = Y;
		else
			Right(Parent(Z)) = Y;
		Parent(Y) = Parent(Z);
		std::swap(Color(Y), Color(Z));
	}
	if (Color(Z) == Black) //check that we didn't disbalance our tree (erase-fixup)
	{
		for (; X != Root() && Color(X) == Black; Xpar = Parent(X))
		{
			if (X == Left(Xpar))
			{
				Nodeptr W = Right(Xpar);
				if (Color(W) == Red)
				{
					Color(W) = Black;
					Color(Xpar) = Red;
					Lrotate(Xpar);
					W = Right(Xpar);
				}
				if (Isnil(W))
					X = Xpar; // shouldn't happen
				else if (Color(Left(W)) == Black && Color(Right(W)) == Black)
				{
					Color(W) = Red;
					X = Xpar;
				}
				else
				{
					if (Color(Right(W)) == Black)
					{
						Color(Left(W)) = Black;
						Color(W) = Red;
						Rrotate(W);
						W = Right(Xpar);
					}
					Color(W) = Color(Xpar);
					Color(Xpar) = Black;
					Color(Right(W)) = Black;
					Lrotate(Xpar);
					break;
				}
			}
			else
			{
				Nodeptr W = Left(Xpar);
				if (Color(W) == Red)
				{
					Color(W) = Black;
					Color(Xpar) = Red;
					Rrotate(Xpar);
					W = Left(Xpar);
				}
				if (Isnil(W))
					X = Xpar; //shouldn't happen
				else if (Color(Right(W)) == Black && Color(Left(W)) == Black)
				{
					Color(W) = Red;
					X = Xpar;
				}
				else
				{
					if (Color(Left(W)) == Black)
					{
						Color(Right(W)) = Black;
						Color(W) = Red;
						Lrotate(W);
						W = Left(Xpar);
					}
					Color(W) = Color(Xpar);
					Color(Xpar) = Black;
					Color(Left(W)) = Black;
					Rrotate(Xpar);
					break;
				}
			}
		}
		Color(X) = Black;
	}
	Destval(&Value(Z));
	Freenode(Z);
	if (0 < Size)
		--Size;
	return P;
}

template<class T>
typename tree<T>::iterator tree<T>::erase(iterator F, iterator L) {
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

template<class Tree_traits>
typename tree<Tree_traits>::size_type tree<Tree_traits>::erase(const key_type& x) {
	Pairii P = equal_range(x);
	size_type N = 0;
	Distance(P.first, P.second, N);
	erase(P.first, P.second);
	return (N);
}

template<class Tree_traits>
void tree<Tree_traits>::erase(const key_type *F, const key_type *L) {
	while (F != L) {
		erase(*F++);
	}
}

template<class Tree_traits>
void tree<Tree_traits>::clear() {
	erase(begin(), end());
}

}

#endif //TREE_MODIFIERS_HPP
