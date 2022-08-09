#ifndef ALGORITHM_MISMATCH_HPP
#define ALGORITHM_MISMATCH_HPP

#include "../utility/utility.hpp"

namespace ft {

template<class InIt1, class InIt2> inline
ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X) {
	for (; F != L && *F == *X; ++F, ++X) {
		;
	}
	return (ft::pair<InIt1, InIt2>(F, X));
}

template<class InIt1, class InIt2, class Pr> inline
ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P) {
	for (; F != L && P(*F, *X); ++F, ++X) {
		;
	}
	return (ft::pair<InIt1, InIt2>(F, X));
}


}

#endif //ALGORITHM_MISMATCH_HPP
