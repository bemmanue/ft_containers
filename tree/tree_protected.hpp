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
		} Consval() {

		}
	}

}

template<class T>
void tree<T>::Erase(nodeptr x) {

}

template<class T>
void tree<T>::Init() {

}

template<class T>
typename tree<T>::tree_iterator tree<T>::insert(bool Addleft, nodeptr Y, const value_type& v) {

}

template<class T>
typename tree<T>::nodeptr tree<T>::Lbound(const key_type& Kv) const {

}

template<class T>
typename tree<T>::nodeptr& tree<T>::Lmost() {

}

template<class T>
typename tree<T>::nodeptr& tree<T>::Lmost() const {

}

template<class T>
void tree<T>::Lrotate(nodeptr x) {

}

template<class T>
typename tree<T>::nodeptr tree<T>::Max(nodeptr P) {

}

template<class T>
typename tree<T>::nodeptr tree<T>::Min(nodeptr P) {

}

template<class T>
typename tree<T>::nodeptr& tree<T>::Rmost() {

}

template<class T>
typename tree<T>::nodeptr& tree<T>::Rmost() const {

}

template<class T>
typename tree<T>::nodeptr& tree<T>::Root() {

}

template<class T>
typename tree<T>::nodeptr& tree<T>::Root() const {

}

template<class T>
void tree<T>::Rrotate(nodeptr x) {

}

template<class T>
typename tree<T>::nodeptr tree<T>::Ubound(const key_type& Kv) const {

}

template<class T>
typename tree<T>::nodeptr tree<T>::Buynode(nodeptr parg, char Carg) {

}

template<class T>
void tree<T>::Consval(tptr P, const value_type& V) {

}

template<class T>
void tree<T>::Destval(tptr P) {

}

template<class T>
void tree<T>::Freenode(nodeptr S) {

}

}


#endif //FT_CONTAINERS_TREE_PROTECTED_HPP
