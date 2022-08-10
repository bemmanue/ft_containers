#ifndef ITERATOR_BASE_HPP
#define ITERATOR_BASE_HPP

#include "iostream"

namespace ft {

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator {
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
};

//template<class Tree_traits, class Distance, class Pointer, class Reference>
//struct Bidit: public const_iterator<bidirectional_iterator_tag, Tree_traits, Distance, Pointer, Reference> {};
//
//template<class Tree_traits, class Distance, class Pointer, class Reference>
//struct Ranit: public const_iterator<random_access_iterator_tag, Tree_traits, Distance, Pointer, Reference> {};
//
//template<class Tree_traits, class Distance, class Pointer, class Reference>
//struct Outit: public const_iterator<output_iterator_tag, void, void, void, void> {};

}

#endif // ITERATOR_BASE_HPP
