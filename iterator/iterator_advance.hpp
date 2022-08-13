#ifndef ITERATOR_ADVANCE_HPP
#define ITERATOR_ADVANCE_HPP

#include "iterator_tags.hpp"

namespace ft {

template<class InIt, class Distance> inline
void	advance(InIt& I, Distance N) {
	Advance(I, N, Iter_cat(I));
}

template<class InIt, class Distance> inline
void	Advance(InIt& iterator, Distance n, input_iterator_tag) {
	for (; 0 < n; --n)
		++iterator;
}

template<class FwdIt, class Distance> inline
void	Advance(FwdIt& iterator, Distance n, forward_iterator_tag) {
	for (; 0 < n; --n)
		++iterator;
}

template<class BidIt, class Distance> inline
void	Advance(BidIt& iterator, Distance n, bidirectional_iterator_tag) {
	for (; 0 < n; --n)
		++iterator;
	for (; n < 0; ++n)
		--iterator;
}

template<class RanIt, class Distance> inline
void	Advance(RanIt& iterator, Distance n, random_access_iterator_tag) {
	iterator += n;
}

}

#endif //ITERATOR_ADVANCE_HPP
