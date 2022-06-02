#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <iterator>
#include "iterator_tags.hpp"

namespace ft {

template<class Iterator>
class iterator_traits {
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::distance_type		distance_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
};

template<class T>
class iterator_traits<T *> {
	typedef random_access_iterator_tag				iterator_category;
	typedef T										value_type;
	typedef ptrdiff_t								distance_type;
	typedef T*										pointer;
	typedef T&										reference;
};

template<class T>
class iterator_traits<const T *> {
	typedef random_access_iterator_tag				iterator_category;
	typedef T										value_type;
	typedef ptrdiff_t								distance_type;
	typedef T*										pointer;
	typedef T&										reference;
};

}

#endif