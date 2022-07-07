#ifndef FT_CONTAINERS_TREE_CONST_ITERATOR_HPP
#define FT_CONTAINERS_TREE_CONST_ITERATOR_HPP

#include "../iterator/iterator.hpp"

namespace ft {

class tree_const_iterator : public ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, ctptr, const_reference> {

public:
	typedef ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, ctptr, const_reference> Mybase;
	typedef typename Mybase::iterator_category	iterator_category;
	typedef typename Mybase::value_type 		value_type;
	typedef typename Mybase::difference_type 	difference_type;
	typedef typename Mybase::pointer 			pointer;
	typedef typename Mybase::reference 			reference;

	tree_const_iterator() : ptr(0) {}
	tree_const_iterator(nodeptr P) : ptr(P) {}
	tree_const_iterator(const typename tree<T>::iterator& x) : ptr(x.mynode()) {}

	const_reference operator*() const {}
	tptr operator->() const {}
	tree_const_iterator& operator++() {}
	tree_const_iterator operator++(int) {}
	tree_const_iterator& operator--() {}
	tree_const_iterator operator--(int) {}
	bool operator==(const tree_iterator x) const {}
	bool operator!=(const tree_iterator x) const {}
	void dec() {}
	void Inc() {}
	nodeptr mynode() const {}

protected:
	nodeptr ptr;
};

}


#endif //FT_CONTAINERS_TREE_CONST_ITERATOR_HPP
