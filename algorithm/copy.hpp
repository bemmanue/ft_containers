#pragma once

namespace ft
{
template <class InIt, class OutIt>
InIt copy_forward(InIt x, OutIt first, OutIt last)
{
	while (first != last)
	{
		*x++ = *first++;
	}
	return (x);
}

template <class BidIt1, class BidIt2>
BidIt1 copy_backward(BidIt1 x, BidIt2 first, BidIt2 last)
{
	while (first != last)
	{
		*--x = *--last;
	}
	return (x);
}

}