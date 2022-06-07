#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/random_access_iterator.hpp"

namespace ft
{

template <class T, class Alloc = std::allocator<T> > class vector
{
public:
	typedef T															value_type;
	typedef std::allocator<T>											allocator_type;
	typedef typename allocator_type::size_type							size_type;
	typedef typename allocator_type::difference_type					difference_type;
	typedef typename allocator_type::reference							reference;
	typedef typename allocator_type::const_reference					const_reference;
	typedef typename allocator_type::pointer							pointer;
	typedef typename allocator_type::const_pointer						const_pointer;
	typedef typename ft::random_access_iterator
		<value_type, difference_type, pointer, reference>				iterator;
	typedef typename ft::random_access_iterator
		<value_type, difference_type, const_pointer, const_reference>	const_iterator;
	typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;

	pointer			_first;
	pointer			_last;
	allocator_type	_allocator;

	explicit vector(const allocator_type& alloc = allocator_type());
	explicit vector(size_t n, const allocator_type& alloc = allocator_type());
	template <class InputIterator> vector(InputIterator first, InputIterator last);
	vector(const vector& x);
	~vector();
	vector& operator= (const vector& x);


	//Elements access

	reference 				operator[] (size_type n);
	const_reference			operator[] (size_type n) const;
	reference				at(size_type n);
	const_reference			at(size_type n) const;
	reference				front();
	const_reference			front() const;
	reference 				back();
	const_reference 		back() const;


	//Iterators

	iterator				begin();
//	const_iterator			begin() const;
	iterator				end();
//	const_iterator			end() const;
//	reverse_iterator		rbegin();
//	const_reverse_iterator	rbegin() const;
//	reverse_iterator		rend();
//	const_reverse_iterator	rend() const;


	//Capacity

	bool empty() const;
	size_type size() const;
	size_type max_size() const;
	void reserve(size_type new_cap);
	size_type capacity() const;


	//Modifiers

	void clear();
	iterator insert( iterator pos, const T& value );
	void insert( iterator pos, size_type count, const T& value );
	template< class InputIt >
	void insert( iterator pos, InputIt first, InputIt last );
	iterator erase( iterator pos );
	iterator erase( iterator first, iterator last );
	void push_back( const T& value );
	void pop_back();
	void resize( size_type count );
	void resize( size_type count, T value = T() );
	void swap( vector& other );

};

}

#include "constructors.hpp"
#include "iterators.hpp"
#include "elements_access.hpp"

#endif
