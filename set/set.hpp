#ifndef FT_CONTAINERS_SET_HPP
#define FT_CONTAINERS_SET_HPP

#include <iostream>

#include "../iterator/iterator.hpp"
#include "set_traits.hpp"
#include "../tree/tree.hpp"

namespace ft {

template<class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
class set : public tree<set_traits<Key, Compare, Allocator> > {
	public:
		typedef set<Key, Compare, Allocator>				Myt;
		typedef tree<set_traits<Key, Compare, Allocator> >	Mybase;
		typedef Key											key_type;
		typedef typename Mybase::value_type					value_type;
		typedef typename Mybase::size_type 					size_type;
		typedef typename Mybase::difference_type 			difference_type;
		typedef Compare										key_compare;
		typedef typename Mybase::value_compare				value_compare;
		typedef typename Mybase::allocator_type				allocator_type;
		typedef typename Mybase::reference 					reference;
		typedef typename Mybase::const_reference 			const_reference;
		typedef typename Mybase::pointer					pointer;
		typedef typename Mybase::const_pointer 				const_pointer;
		typedef typename Mybase::tree_iterator				iterator;
		typedef typename Mybase::tree_const_iterator		const_iterator;
		typedef typename Mybase::reverse_iterator			reverse_iterator;
		typedef typename Mybase::const_reverse_iterator		const_reverse_iterator;

		// member functions
		set();
		explicit set(const Compare& comp, const Allocator& alloc = Allocator());
		template<class InputIt>
				set(InputIt first, InputIt last,
				const Compare& comp = Compare(), const Allocator& alloc = Allocator());
		set(const set& other);

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
//		std::pair<const_iterator,bool> insert(const value_type& value);
//		const_iterator insert(const_iterator hint, const value_type& value);
//		template<class InputIt>
//		void insert(InputIt first, InputIt last);
//		void erase(const_iterator pos);
//		void erase(const_iterator first, const_iterator last);
//		size_type erase(const Key& key);
//		void swap(set& other);

		// lookup
//		size_type count(const Key& key) const;
//		const_iterator find(const Key& key);
//		const_iterator find(const Key& key) const;
//		std::pair<const_iterator,const_iterator> equal_range(const Key& key);
//		std::pair<const_iterator,const_iterator> equal_range(const Key& key) const;
//		const_iterator lower_bound(const Key& key);
//		const_iterator lower_bound(const Key& key) const;
//		const_iterator upper_bound(const Key& key);
//		const_iterator upper_bound(const Key& key) const;

		// observers
//		key_compare key_comp() const;
//		set::value_compare value_comp() const;

};

}


#endif //FT_CONTAINERS_SET_HPP
