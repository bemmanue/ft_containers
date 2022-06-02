#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "iterator_tags.hpp"

namespace ft
{

template<class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class random_access_iterator : iterator<random_access_iterator_tag, T, Distance, Pointer, Reference>
{
public:
	random_access_iterator();
	explicit random_access_iterator(Pointer pointer);

	Reference	operator+=	(Distance n);
	T			operator+ 	(Distance n);
	Reference	operator-= 	(Distance n);
	T			operator-	(Distance n);
	Distance	operator-	(T a);
	Reference	operator[]	(T i);
	bool		operator<	(T b);
	bool		operator>	(T b);
	bool		operator<=	(T b);
	bool		operator>=	(T b);

private:
	Pointer		_pointer;
};

template<class T, class Distance, class Pointer, class Reference>
random_access_iterator<T, Distance, Pointer, Reference>::random_access_iterator() {

};

template<class T, class Distance, class Pointer, class Reference>
random_access_iterator<T, Distance, Pointer, Reference>::random_access_iterator(Pointer pointer) {

};

template<class T, class Distance, class Pointer, class Reference>
Reference random_access_iterator<T, Distance, Pointer, Reference>::operator+= (Distance n) {
	return _pointer + n;
};

template<class T, class Distance, class Pointer, class Reference>
T random_access_iterator<T, Distance, Pointer, Reference>::operator+ (Distance n) {

};

template<class T, class Distance, class Pointer, class Reference>
Reference random_access_iterator<T, Distance, Pointer, Reference>::operator-= (Distance n) {

};

template<class T, class Distance, class Pointer, class Reference>
T random_access_iterator<T, Distance, Pointer, Reference>::operator- (Distance n) {

};

template<class T, class Distance, class Pointer, class Reference>
Reference random_access_iterator<T, Distance, Pointer, Reference>::operator[] (T i) {

};

template<class T, class Distance, class Pointer, class Reference>
bool random_access_iterator<T, Distance, Pointer, Reference>::operator< (T b) {

};

template<class T, class Distance, class Pointer, class Reference>
bool random_access_iterator<T, Distance, Pointer, Reference>::operator> (T b) {

};

template<class T, class Distance, class Pointer, class Reference>
bool random_access_iterator<T, Distance, Pointer, Reference>::operator<= (T b) {

};

template<class T, class Distance, class Pointer, class Reference>
bool random_access_iterator<T, Distance, Pointer, Reference>::operator>= (T b) {

};

}

#endif
