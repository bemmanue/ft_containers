#ifndef STACK_NON_MEMBER_FUNCTIONS_HPP
#define STACK_NON_MEMBER_FUNCTIONS_HPP

#include "stack.hpp"

namespace ft {

template<class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (lhs == rhs);
}

template<class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (!(lhs == rhs));
}

template<class T, class Container>
bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (lhs < rhs);
}

template<class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (lhs <= rhs);
}


template<class T, class Container>
bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (lhs > rhs);
}

template<class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (lhs >= rhs);
}

}

#endif // STACK_NON_MEMBER_FUNCTIONS_HPP
