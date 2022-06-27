#pragma once

#include "iterator.hpp"

namespace ft
{

template <class InIt> inline
typename iterator_traits<InIt>::difference_type distance(InIt first, InIt last)
{
	typename iterator_traits<InIt>::difference_type n = 0;
	Distance2(first, last, n, Iter_cat(first));
	return (n);
}

template <class InIt, class Distance> inline
void Distance(InIt first, InIt last, Distance& n)
{
	Distance2(first, last, n, Iter_cat(first));
}

template <class InIt, class Distance> inline
void Distance2(InIt first, InIt last, Distance& n, input_iterator_tag)
{
	while (first++ != last)
	{
		++n;
	}
}

template <class InIt, class Distance> inline
void Distance2(InIt first, InIt last, Distance& n, forward_iterator_tag)
{
	while (first++ != last)
	{
		++n;
	}
}

template <class InIt, class Distance> inline
void Distance2(InIt first, InIt last, Distance& n, bidirectional_iterator_tag)
{
	while (first++ != last)
	{
		++n;
	}
}

template <class InIt, class Distance> inline
void Distance2(InIt first, InIt last, Distance& n, random_access_iterator_tag)
{
	n += last - first;
}

template <class InIt, class Distance> inline
void Distance_Tree(InIt first, InIt last, Distance& n)
{
	while (first++ != last)
	{
		++n;
	}
}

}
