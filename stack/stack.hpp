#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include <iostream>
#include <deque>

namespace ft {

template<class T, class Container = std::deque<T> >
class stack {
	public:
		typedef Container						container_type;
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;

		stack();
		explicit stack(const container_type& cont);
		~stack();
		stack& operator=(const stack& other);

		value_type& top();
		const value_type& top() const;

		bool empty() const;
		size_type size() const;

		void push(const value_type& x);
		void pop();

	protected:
		Container container;
};

}


#endif //FT_CONTAINERS_STACK_HPP
