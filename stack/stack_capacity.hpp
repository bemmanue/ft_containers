#ifndef STACK_CAPACITY_HPP
#define STACK_CAPACITY_HPP

#include "stack.hpp"

namespace ft {

// checks whether the underlying container is empty
template<class T, class Container>
bool stack<T, Container>::empty() const {
	return (container.empty());
}

// returns the number of elements
template<class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
	return (container.size());
}

}

#endif // STACK_CAPACITY_HPP
