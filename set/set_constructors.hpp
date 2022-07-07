#ifndef FT_CONTAINERS_SET_CONSTRUCTORS_HPP
#define FT_CONTAINERS_SET_CONSTRUCTORS_HPP

#include "set.hpp"

namespace ft {

	template<class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>::set()
			: Mybase(key_compare(), allocator_type()){
	}

	template<class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>::set(const Compare& comp, const Allocator& alloc)
			: Mybase(comp, alloc) {

	}

	template<class Key, class Compare, class Allocator>
	template<class InputIt>
	set<Key, Compare, Allocator>::set(InputIt first, InputIt last, const Compare& comp, const Allocator& alloc)
			: Mybase(comp, alloc) {
		for (; first != last; ++first) {
			insert(*first);
		}
	}

}


#endif //FT_CONTAINERS_SET_CONSTRUCTORS_HPP
