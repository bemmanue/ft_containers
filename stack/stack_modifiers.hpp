#ifndef STACK_MODIFIERS_HPP
#define STACK_MODIFIERS_HPP

#include "stack.hpp"

namespace ft {

// inserts element at the top
template<class T, class Container>
void stack<T, Container>::push(const value_type& x) {
	container.push_back(x);
}

// removes the top element
template<class T, class Container>
void stack<T, Container>::pop() {
	container.pop_back();
}

}

#endif // STACK_MODIFIERS_HPP
