#ifndef FT_CONTAINERS_tREE_OPERATORS_HPP
#define FT_CONTAINERS_tREE_OPERATORS_HPP

#include "tree.hpp"

namespace ft {

template <class Traits> inline
void swap(tree<Traits>& X, tree<Traits>& Y) {
	X.swap(Y);
}

template <class Traits> inline
bool operator== (const tree<Traits>& X, const tree<Traits>& Y) {
	return (X.size() == Y.size() && equal(X.begin(), X.end(), Y.begin()));
}

template <class Traits> inline
bool operator!= (const tree<Traits>& X, const tree<Traits>& Y) {
	return !(X == Y);
}

template <class Traits> inline
bool operator< (const tree<Traits>& X, const tree<Traits>& Y) {
	return ft::lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end(), X.value_comp());
}

template <class Traits> inline
bool operator> (const tree<Traits>& X, const tree<Traits>& Y) {
	return Y < X;
}

template <class Traits> inline
bool operator<= (const tree<Traits>& X, const tree<Traits>& Y) {
	return !(Y < X);
}

template <class Traits> inline
bool operator>= (const tree<Traits>& X, const tree<Traits>& Y) {
	return !(X < Y);
}

}


#endif //FT_CONTAINERS_tREE_OPERATORS_HPP
