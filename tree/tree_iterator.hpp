#ifndef FT_CONTAINERS_TREE_ITERATOR_HPP
#define FT_CONTAINERS_TREE_ITERATOR_HPP

#include "../iterator/iterator.hpp"

namespace ft {

class tree_iterator : public ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> {

public:
	typedef ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> Mybase;
	typedef typename Mybase::iterator_category	iterator_category;
	typedef typename Mybase::value_type 		value_type;
	typedef typename Mybase::difference_type 	difference_type;
	typedef typename Mybase::pointer 			pointer;
	typedef typename Mybase::reference 			reference;

	tree_iterator() : ptr(0) {}
	tree_iterator(nodeptr P) : ptr(P) {}

	reference operator*() const {}
	tptr operator->() const {}
	tree_iterator& operator++() {}
	tree_iterator operator++(int) {}
	tree_iterator& operator--() {}
	tree_iterator operator--(int) {}
	bool operator==(const tree_iterator x) const {}
	bool operator!=(const tree_iterator x) const {}
	void dec() {}
	void Inc() {}
	nodeptr mynode() const {}

protected:
	nodeptr ptr;
};

}

#endif //FT_CONTAINERS_TREE_ITERATOR_HPP
