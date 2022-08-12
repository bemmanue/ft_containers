#ifndef STACK_ELEMENT_ACCESS_HPP
#define STACK_ELEMENT_ACCESS_HPP

#include "stack_base.hpp"

namespace ft {

template<class T, class Container>
typename stack<T, Container>::reference stack<T, Container>::top() {
	return container.back();
}

template<class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() const {
	return container.back();
}

}

#endif // STACK_ELEMENT_ACCESS_HPP
