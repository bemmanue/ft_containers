#ifndef STACK_OPERATOR_OVERLOADS_HPP
#define STACK_OPERATOR_OVERLOADS_HPP

#include "stack_base.hpp"

namespace ft {

template<class T, class Container>
bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return lhs.container == rhs.container;
}

template<class T, class Container>
bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return (!(lhs == rhs));
}

template<class T, class Container>
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return lhs.container < rhs.container;
}

template<class T, class Container>
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return lhs.container > rhs.container;
}

template<class T, class Container>
bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return !(lhs < rhs);
}

template<class T, class Container>
bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return !(lhs > rhs);
}

}

#endif //STACK_OPERATOR_OVERLOADS_HPP
