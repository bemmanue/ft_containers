#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>

namespace ft
{

template <class T, class Alloc = std::allocator<T> > class vector
{
public:
	typedef T											value_type;
	typedef std::allocator<T>							allocator_type;
	typedef typename std::allocator<T>::size_type		size_type;
	typedef typename std::allocator<T>::difference_type	difference_type;
	typedef typename std::allocator<T>::reference		reference;
	typedef typename std::allocator<T>::const_reference	const_reference;
	typedef typename std::allocator<T>::pointer			pointer;
	typedef typename std::allocator<T>::const_pointer	const_pointer;
	iterator;
	const_iterator;
	reverse_iterator;
	const_reverse_iterator;

	pointer					_first;
	pointer					_last;
	allocator_type			_allocator;

	explicit vector(const allocator_type& alloc = allocator_type());
	explicit vector(size_t n, const allocator_type& alloc = allocator_type());
	template <class InputIterator>
		vector(InputIterator first, InputIterator last);
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
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;
};

}

#endif
