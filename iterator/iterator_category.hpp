#pragma once

#include "iterator.hpp"

namespace ft
{

    template<class Category, class T, class Distance> inline
    Category Iter_cat(const iterator<Category, T, Distance>)
    {
        Category x;
        return (x);
    }

    template<class T> inline
    random_access_iterator_tag Iter_cat(const T*)
    {
        random_access_iterator_tag x;
        return (x);
    }

}