#ifndef FT_CONTAINERS_SET_HPP
#define FT_CONTAINERS_SET_HPP

#include <iostream>

#include "../iterator/iterator.hpp"

namespace ft {

template<class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
class set {
	public:
		typedef Key										key_type;
		typedef Key										value_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t 							difference_type;
		typedef Compare									key_compare;
		typedef Compare									value_compare;
		typedef Allocator								allocator_type;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;
		typedef T0										iterator;
		typedef T1										const_iterator;
		typedef T2										size_type;
		typedef T3 										difference_type;
		typedef reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef reverse_iterator<iterator>				reverse_iterator;

		// member functions
//		set();
//		explicit set( const Compare& comp, const Allocator& alloc = Allocator());
//		template<class InputIt>
//		set(InputIt first, InputIt last,
//			const Compare& comp = Compare(),
//			const Allocator& alloc = Allocator());
//		set(const set& other);
//
//		~set();
//		set& operator=(const set& other);
//		allocator_type get_allocator() const;

		// iterators
//		iterator begin();
//		const_iterator begin() const;
//		iterator end();
//		const_iterator end() const;
//		iterator rbegin();
//		const_iterator rbegin() const;
//		iterator rend();
//		const_iterator rend() const;

		// capacity
//		bool empty() const;
//		size_type size() const;
//		size_type max_size() const;

		// modifiers
//		void clear();
//		std::pair<iterator,bool> insert(const value_type& value);
//		iterator insert(iterator hint, const value_type& value);
//		template<class InputIt>
//		void insert(InputIt first, InputIt last);
//		void erase(iterator pos);
//		void erase(iterator first, iterator last);
//		size_type erase(const Key& key);
//		void swap(set& other);

		// lookup
//		size_type count(const Key& key) const;
//		iterator find(const Key& key);
//		const_iterator find(const Key& key) const;
//		std::pair<iterator,iterator> equal_range(const Key& key);
//		std::pair<const_iterator,const_iterator> equal_range(const Key& key) const;
//		iterator lower_bound(const Key& key);
//		const_iterator lower_bound(const Key& key) const;
//		iterator upper_bound(const Key& key);
//		const_iterator upper_bound(const Key& key) const;

		// observers
//		key_compare key_comp() const;
//		set::value_compare value_comp() const;

};

}


#endif //FT_CONTAINERS_SET_HPP
