#ifndef STACK_MEMBER_FUNCTIONS_HPP
#define STACK_MEMBER_FUNCTIONS_HPP

#include "stack.hpp"

namespace ft {

// constructs the stack
template<class T, class Container>
stack<T, Container>::stack() : container() {}

// constructs the stack
template<class T, class Container>
stack<T, Container>::stack(const container_type& cont) : container(cont) {}

// destructs the stack
template<class T, class Container>
stack<T, Container>::~stack() {}

// assigns values to the container adaptor
template<class T, class Container>
typename stack<T, Container>::stack& stack<T, Container>::operator=(const stack& other) {
	container = other;
}

}

#endif // STACK_MEMBER_FUNCTIONS_HPP
