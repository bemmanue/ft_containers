#ifndef MAP_HPP
#define MAP_HPP

#include "../tree/tree.hpp"
#include "map_traits.hpp"

namespace ft {

template<class Key, class T, class Pred = std::less<Key>, class A = std::allocator<ft::pair<const Key, T> > >
class map : public ft::tree<map_traits<Key, T, Pred, A> > {
	public:
		typedef	map<Key, Pred, A>							Myt;
		typedef ft::tree<map_traits<Key, T, Pred, A> >		Mybase;
		typedef Key											key_type;
		typedef T											mapped_type;
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

		map() : Mybase(key_compare(), allocator_type()) {}

		explicit map(const key_compare& pred) : Mybase(pred, allocator_type()) {}

		map(const key_compare& pred, const A& Al) : Mybase(pred, Al) {}

		template <class It>
		map(It F, It L) : Mybase(key_compare(), allocator_type()) {
			for (; F != L; ++F) {
				this->insert(*F);
			}
		}

		template <class It>
		map(It first, It last, const key_compare& pred) : Mybase(pred, allocator_type()) {
			for (; first != last; ++first) {
				this->insert(*first);
			}
		}

		template <class It>
		map(It F, It L, const key_compare& pred, const allocator_type& al) : Mybase(pred, al) {
			for (; F != L; ++F) {
				this->insert(*F);
			}
		}

		~map() {
			Mybase::clear();
		}

		mapped_type& operator[](const key_type& Kv) {
			iterator P = this->insert(value_type(Kv, mapped_type())).first;
			return (*P).second;
		}

		mapped_type& at(const key_type& Kv) {
			iterator P = this->find(Kv);
			if (P == this->end())
				throw std::out_of_range("No such element in map");
			return (*P).second;
		}
};

}

#endif //MAP_HPP
