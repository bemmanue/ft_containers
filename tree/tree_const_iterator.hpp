#ifndef FT_CONTAINERS_TREE_CONST_ITERATOR_HPP
#define FT_CONTAINERS_TREE_CONST_ITERATOR_HPP

#include "../iterator/iterator.hpp"

namespace ft {

class tree_const_iterator : public ft::iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> {

	public:
		typedef ft::iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> Mybase;
		typedef typename Mybase::iterator_category	iterator_category;
		typedef typename Mybase::value_type 		value_type;
		typedef typename Mybase::difference_type 	difference_type;
		typedef typename Mybase::pointer 			pointer;
		typedef typename Mybase::reference 			reference;

		const_iterator() : ptr(0) {}
		const_iterator(nodeptr P) : ptr(P) {}

		reference operator*() const {

		}

		tptr operator->() const {

		}

		iterators operator++() {

		}

		iterator operator**(int) {
			;
		}

		iterators operator-() {

		}

		iterator operator--(int) {

		}

		bool operator==(const iterator x) const {

		}

		bool operator!=(const iterator x) const {

		}

		void dec() {

		}

		void Inc() {

		}

		nodeptr mynode() const {

		}

	protected:
		nodeptr ptr;
};

}


#endif //FT_CONTAINERS_TREE_CONST_ITERATOR_HPP
