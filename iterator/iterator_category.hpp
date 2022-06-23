#pragma once

#include "iterator.hpp"

namespace ft
{

    template<class Category, class T, class Distance> inline
    Category Iter_cat(const iterator<Category, T, Distance>)
    {
        Category x;
        return x;
    }

    template<class T> inline
    random_access_iterator_tag Iter_cat(const T*)
    {
        random_access_iterator_tag x;
        return x;
    }

	inline Int_iterator_tag Iter_cat(bool)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(char)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(signed char)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(unsigned char)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(wchar_t)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(short)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(unsigned short)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(int)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(unsigned int)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(long)
	{
		Int_iterator_tag x;
		return x;
	}

	inline Int_iterator_tag Iter_cat(unsigned long)
	{
		Int_iterator_tag x;
		return x;
	}

}
