#ifndef FT_CONTAINERS_TREE_ITERATOR_HPP
#define FT_CONTAINERS_TREE_ITERATOR_HPP

#include "../iterator/iterator.hpp"
#include "tree.hpp"

namespace ft {

class tree_iterator : public ft::iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> {
	public:
		typedef ft::iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> Mybase;
		typedef typename Mybase::iterator_category	iterator_category;
		typedef typename Mybase::value_type 		value_type;
		typedef typename Mybase::difference_type 	difference_type;
		typedef typename Mybase::pointer 			pointer;
		typedef typename Mybase::reference 			reference;

		tree_iterator() : ptr(0) {}

		tree_iterator(nodeptr P) : ptr(P) {}

		reference operator*() const {}

		tptr operator->() const {
			return (&**this);
		}

		tree_iterator& operator++() {
			inc();
			return (*this);
		}

		tree_iterator operator++(int) {
			tree_iterator temp = *this;
			++*this;
			return (temp);
		}

		tree_iterator& operator--() {
			dec();
			return (*this);
		}

		tree_iterator operator--(int) {
			tree_iterator temp = *this;
			--*this;
			return ;
		}

		bool operator==(const tree_iterator x) const {
			return (ptr == x.ptr);
		}

		bool operator!=(const tree_iterator x) const {
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

#endif //FT_CONTAINERS_TREE_ITERATOR_HPP
