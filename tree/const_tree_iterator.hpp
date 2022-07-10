#ifndef FT_CONTAINERS_CONST_TREE_ITERATOR_HPP
#define FT_CONTAINERS_CONST_TREE_ITERATOR_HPP

#include "../iterator/iterator.hpp"
#include "tree.hpp"

namespace ft {

class const_tree_iterator : public ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, ctptr, const_reference> {{
	public:
		typedef ft::iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> Mybase;
		typedef typename Mybase::iterator_category	iterator_category;
		typedef typename Mybase::value_type 		value_type;
		typedef typename Mybase::difference_type 	difference_type;
		typedef typename Mybase::pointer 			pointer;
		typedef typename Mybase::reference 			reference;

		const_tree_iterator() : ptr(0) {}

		const_tree_iterator(nodeptr P) : ptr(P) {}

		const_tree_iterator(const typename tree<Traits>::iterator& x)
				: ptr(x.mynode()) {}

		const_reference operator*() const {
			return (value(ptr));
		}

		tptr operator->() const {
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
				nodeptr P;
				while (!isnil(P = parent(ptr)) && ptr == left(P)) {
					ptr = P;
				}
				if (!isnil(P)) {
					ptr = P;
				}
			}
		}

		void inc() {
			if (isnil(ptr)) {
				;
			} else if (!isnil(left(ptr))) {
				ptr = min(right(ptr));
			} else {
				nodeptr P;
				while (!isnil(P = parent(ptr)) && ptr == right(P)) {
					ptr = P;
				}
				ptr = P;
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
