#ifndef STACK_CAPACITY_HPP
#define STACK_CAPACITY_HPP

#include "stack_base.hpp"

namespace ft {

template<class T, class Container>
bool stack<T, Container>::empty() const {
	return container.empty();
}

template<class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
	return container.size();
}

}

#endif //STACK_CAPACITY_HPP
