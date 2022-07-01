#ifndef STACK_ELEMENT_ACCESS_HPP
#define STACK_ELEMENT_ACCESS_HPP

#include "stack.hpp"

namespace ft {

// accesses the top element
template<class T, class Container>
typename stack<T, Container>::value_type& stack<T, Container>::top() {
	return (container.back());
}

// accesses the top element
template<class T, class Container>
const typename stack<T, Container>::value_type& stack<T, Container>::top() const {
	return (container.back());
}

}

#endif // STACK_ELEMENT_ACCESS_HPP
