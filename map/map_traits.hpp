#ifndef MAP_TRAITS_HPP
#define MAP_TRAITS_HPP

#include "../utility/utility.hpp"

namespace ft {

template <class Key, class T, class Pred, class Allocator>
class map_traits {
	public:
		typedef Key								key_type;
		typedef ft::pair<const Key, T>			value_type;
		typedef Pred							key_compare;
		typedef typename Allocator::template
			rebind<value_type>::other			allocator_type;

		map_traits() : comp() {}
		map_traits(Pred Parg) : comp(Parg) {}

		class value_compare : public std::binary_function<value_type, value_type, bool> {
			friend class map_traits<Key, T, Pred, Allocator>;

			protected:
				key_compare	comp;

			public:
				bool operator()(const value_type &x, const value_type &y) const {
					return comp(x.first, y.first);
				}

				value_compare(key_compare Pr) : comp(Pr) {}
		};

		const static Key &GetKey(const value_type &V) {
			Kfn	ret;
			return ret(V);
		}

		struct Kfn {
			const Key& operator()(const value_type& x) const {
				return x.first;
			}
		};

		Pred	comp;
};

}

#endif //MAP_TRAITS_HPP
