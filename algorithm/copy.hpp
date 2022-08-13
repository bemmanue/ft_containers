#ifndef ALGORITHM_COPY_HPP
#define ALGORITHM_COPY_HPP

namespace ft {

template<class InIt, class OutIt>
OutIt	copy_forward(InIt first, InIt last, OutIt x) {
	for (; first != last; ++x, ++first) {
		*x = *first;
	}
	return (x);
}

template<class BidIt1, class BidIt2>
BidIt2	copy_backward(BidIt1 first, BidIt1 last, BidIt2 x) {
	while (first != last) {
		*--x = *--last;
	}
	return (x);
}

}

#endif //ALGORITHM_COPY_HPP
