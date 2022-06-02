#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft {

template<class Iterator>
class reverse_iterator {
public:
	typedef Iterator												iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;

//	reverse_iterator();
//	explicit reverse_iterator (iterator_type it);
//	template <class Iter> reverse_iterator (const reverse_iterator<Iter>& rev_it);
//
//	iterator_type base() const;
//
//	reference operator*() const;
//	reverse_iterator operator+ (difference_type n) const;
//	reverse_iterator& operator++();
//	reverse_iterator  operator++(int);
//	reverse_iterator& operator+= (difference_type n);
//	reverse_iterator operator- (difference_type n) const;
//	reverse_iterator& operator--();
//	reverse_iterator  operator--(int);
//	reverse_iterator& operator-= (difference_type n);
//	pointer operator->() const;
//	reference operator[] (difference_type n) const;
};

}

#endif
