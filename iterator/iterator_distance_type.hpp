#ifndef ITERATOR_DISTANCE_TYPE
#define ITERATOR_DISTANCE_TYPE

#include "iterator.hpp"

namespace ft {

//    template<class It> inline
//    typename iterator_traits::difference_type *Dist_type(It)
//    {
//        return (0);
//    }

template<class C, class T, class D, class Pt, class Rt> inline
D*  Dist_type(tree_iterator<C, T, D, Pt, Rt>) {
	return (0);
}

template <class T> inline
ptrdiff_t*  Dist_type(const T *) {
	return (0);
}

}

#endif
