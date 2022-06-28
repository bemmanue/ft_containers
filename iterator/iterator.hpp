#ifndef ITERATOR_HPP
#define ITERATOR_HPP

# include <memory>
# include <iostream>

namespace ft
{

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator {
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
};

//template<class T, class Distance, class Pointer, class Reference>
//struct Bidit: public iterator<bidirectional_iterator_tag, T, Distance, Pointer, Reference> {};
//
//template<class T, class Distance, class Pointer, class Reference>
//struct Ranit: public iterator<random_access_iterator_tag, T, Distance, Pointer, Reference> {};
//
//template<class T, class Distance, class Pointer, class Reference>
//struct Outit: public iterator<output_iterator_tag, void, void, void, void> {};

}

# include "iterator_tags.hpp"
# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include "iterator_distance.hpp"
# include "iterator_advance.hpp"
# include "reverse_iterator.hpp"
# include "iterator_category.hpp"
# include "iterator_swap.hpp"
# include "value_type.hpp"
# include "distance_type.hpp"

#endif // ITERATOR_HPP
