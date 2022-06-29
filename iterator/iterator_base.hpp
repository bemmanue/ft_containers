#ifndef ITERATOR_BASE_HPP
#define ITERATOR_BASE_HPP

namespace ft {

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

#endif // ITERATOR_BASE_HPP
