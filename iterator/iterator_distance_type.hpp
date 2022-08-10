#ifndef ITERATOR_DISTANCE_TYPE_HPP
#define ITERATOR_DISTANCE_TYPE_HPP

#include "iterator_base.hpp"

namespace ft {

template<class C, class T, class D, class Pt, class Rt> inline
D*  Dist_type(ft::iterator<C, T, D, Pt, Rt>) {
	return 0;
}

template <class T> inline
ptrdiff_t*  Dist_type(const T *) {
	return 0;
}

}

#endif //ITERATOR_DISTANCE_TYPE_HPP
