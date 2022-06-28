#ifndef ALGORITHM_COPY_HPP
#define ALGORITHM_COPY_HPP

namespace ft
{
template <class InIt, class OutIt>
InIt copy_forward(InIt x, OutIt first, OutIt last)
{
	for (; first != last; ++x, ++first) {
		*x = *first;
	}
	return (x);
}

template <class BidIt1, class BidIt2>
BidIt1 copy_backward(BidIt1 x, BidIt2 first, BidIt2 last)
{
//	for (; first != last; --x, --last) {
//		*x = *last;
//	}
//	return (x);
	while (first != last)
	{
		*--x = *--last;
	}
	return (x);
}

}

#endif // ALGORITHM_COPY_HPP
