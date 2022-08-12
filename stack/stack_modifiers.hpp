#ifndef STACK_MODIFIERS_HPP
#define STACK_MODIFIERS_HPP

#include "stack_base.hpp"

namespace ft {

template<class T, class Container>
void stack<T, Container>::push(const value_type& x) {
	container.push_back(x);
}

template<class T, class Container>
void stack<T, Container>::pop() {
	container.pop_back();
}

}

#endif // STACK_MODIFIERS_HPP
