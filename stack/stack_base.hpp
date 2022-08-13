#ifndef STACK_BASE_HPP
#define STACK_BASE_HPP

#include <iostream>
#include "../vector/vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {
	public:
		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

		//Member functions
		stack();
		explicit stack(const container_type& other);
		stack(const stack& other);
		~stack();
		stack& operator=(const stack& copy);

		//Capacity
		size_type		size() const;
		bool			empty() const;

		//Elements access
		reference		top();
		const_reference	top() const;

		//Modifiers
		void			push(const value_type& value);
		void			pop();

		//Member objects
		Container		container;

};

}

#endif //STACK_BASE_HPP
