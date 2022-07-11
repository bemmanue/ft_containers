#ifndef ITERATOR_SWAP
#define ITERATOR_SWAP

#include "iterator.hpp"

namespace ft {

template<class FwdIt1, class FwdIt2> inline
void iter_swap(FwdIt1 x, FwdIt2 y) {
	Iter_swap(x, y, value_type(x));
}

template<class FwdIt1, class FwdIt2, class T> inline
void Iter_swap(FwdIt1 x, FwdIt2 y, T*) {
	T temp = *x;
	*x = *y;
	*y = temp;
}

}

#endif
