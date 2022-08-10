#ifndef ITERATOR_VALUE_TYPE_HPP
#define ITERATOR_VALUE_TYPE_HPP

#include "iterator_traits.hpp"

namespace ft {

template<class It> inline
typename ft::iterator_traits<It>::value_type *value_type(It) {
	return 0;
}

}

#endif //ITERATOR_VALUE_TYPE_HPP