#ifndef SET_HPP
#define SET_HPP

#include "set_traits.hpp"
#include "../tree/tree_base.hpp"

namespace ft {

template<class Key, class Pred = std::less<Key>, class Allocator = std::allocator<Key> >
class set : public ft::tree<ft::set_traits<Key, Pred, Allocator> > {
	public:
		typedef	set <Key, Pred, Allocator>					Myt;
		typedef tree<set_traits<Key, Pred, Allocator> >		Mybase;
		typedef Key											key_type;
		typedef Pred										key_compare;
		typedef typename Mybase::value_type					value_type;
		typedef typename Mybase::value_compare				value_compare;
		typedef typename Mybase::allocator_type				allocator_type;
		typedef typename Mybase::size_type					size_type;
		typedef typename Mybase::difference_type			difference_type;
		typedef typename Mybase::pointer					pointer;
		typedef typename Mybase::const_pointer				const_pointer;
		typedef typename Mybase::reference					reference;
		typedef typename Mybase::const_reference			const_reference;
		typedef typename Mybase::iterator					iterator;
		typedef typename Mybase::const_iterator				const_iterator;
		typedef typename Mybase::reverse_iterator			reverse_iterator;
		typedef typename Mybase::const_reverse_iterator		const_reverse_iterator;

		//Constructors
		set() : Mybase(key_compare(), allocator_type()) {}

		explicit set(const key_compare& pred) : Mybase(pred, allocator_type()) {}

		set(const key_compare& pred, const Allocator& Al) : Mybase(pred, Al) {}

		template <class It>
		set(It F, It L) : Mybase(key_compare(), allocator_type()) {
			for (; F != L; ++F)
				this->insert(*F);
		}

		template <class It>
		set(It first, It last, const key_compare& pred) : Mybase(pred, allocator_type()) {
			for (; first != last; ++first)
				this->insert(*first);
		}

		template <class It>
		set(It F, It L, const key_compare& pred, const allocator_type& al) : Mybase(pred, al) {
			for (; F != L; ++F)
				this->insert(*F);
		}
};

}

#endif //SET_HPP
