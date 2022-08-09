#ifndef ALGORITHM_EQUAL_HPP
#define ALGORITHM_EQUAL_HPP

#include "mismatch.hpp"

namespace ft {

template <class InIt1, class InIt2>
inline bool equal(InIt1 first, InIt1 last, InIt2 ref) {
	return ft::mismatch(first, last, ref).first == last;
}

template <class InIt1, class InIt2, class BinaryPredicate>
inline bool equal(InIt1 first, InIt1 last, InIt2 ref, BinaryPredicate p) {
	return ft::mismatch(first, last, ref, p).first == last;
}

}

#endif //ALGORITHM_EQUAL_HPP
