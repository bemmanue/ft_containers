#ifndef STACK_MEMBER_FUNCTIONS_HPP
#define STACK_MEMBER_FUNCTIONS_HPP

#include "stack_base.hpp"

namespace ft {

template<class T, class Container>
stack<T, Container>::stack() : container(container_type()) {}

template<class T, class Container>
stack<T, Container>::stack(const container_type& other) : container(other) {}

template <class Type_stack, class Container_stack>
stack<Type_stack, Container_stack>::stack(const stack& other)
	: container(other.container) {}

template<class T, class Container>
stack<T, Container>::~stack() {}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(const stack& other) {
	this->container = other.container;
	return *this;
}

}

#endif //STACK_MEMBER_FUNCTIONS_HPP
