#ifndef FT_CONTAINERS_CONST_TREE_ITERATOR_HPP
#define FT_CONTAINERS_CONST_TREE_ITERATOR_HPP

#include "tree.hpp"
#include "../iterator/iterator.hpp"

namespace ft {

template<class Tree_traits>
class tree<Tree_traits>::const_tree_iterator
		: public ft::iterator<bidirectional_iterator_tag, value_type, difference_type, const_pointer, const_reference> {
	public:

		const_tree_iterator() : ptr(0) {}

		const_tree_iterator(nodeptr p) : ptr(p) {}

		const_tree_iterator(const typename ft::tree<Tree_traits>::iterator& x)
				: ptr(x.mynode()) {}

		reference operator*() const {
			return (value(ptr));
		}

		pointer operator->() const {
			return (&**this);
		}

		const_tree_iterator& operator++() {
			inc();
			return (*this);
		}

		const_tree_iterator operator++(int) {
			const_tree_iterator temp = *this;
			++*this;
			return (temp);
		}

		const_tree_iterator& operator--() {
			dec();
			return (*this);
		}

		const_tree_iterator operator--(int) {
			const_tree_iterator temp = *this;
			--*this;
			return ;
		}

		bool operator==(const const_tree_iterator x) const {
			return (ptr == x.ptr);
		}

		bool operator!=(const const_tree_iterator x) const {
			return (!(*this == x));
		}

		void dec() {
			if (isnil(ptr)) {
				ptr = right(ptr);
			} else if (!isnil(left(ptr))) {
				ptr = max(left(ptr));
			} else {
				nodeptr p;
				while (!isnil(p = parent(ptr)) && ptr == left(p)) {
					ptr = p;
				}
				if (!isnil(p)) {
					ptr = p;
				}
			}
		}

		void inc() {
			if (isnil(ptr)) {
				;
			} else if (!isnil(left(ptr))) {
				ptr = min(right(ptr));
			} else {
				nodeptr p;
				while (!isnil(p = parent(ptr)) && ptr == right(p)) {
					ptr = p;
				}
				ptr = p;
			}
		}

		nodeptr mynode() const {
			return (ptr);
		}

	protected:
		nodeptr ptr;
};

}


#endif //FT_CONTAINERS_CONST_TREE_ITERATOR_HPP
