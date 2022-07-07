#ifndef FT_CONTAINERS_SET_TRAITS_HPP
#define FT_CONTAINERS_SET_TRAITS_HPP

namespace ft {

template<class K, class Pr, class Ax>
class set_traits {

	public:
		typedef K	key_type;
		typedef K	value_type;
		typedef Pr	key_compare;
		typedef typename Ax::template rebind<value_type>::other allocator_type;

		set_traits() : comp() {}
		set_traits(Pr parg) : comp(parg) {}

		typedef key_compare	value_compare;

		struct Kfn {
			const K& operator() (const value_type& X) const {
				return X;
			}
		};

		Pr	comp;
};

}

#endif //FT_CONTAINERS_SET_TRAITS_HPP
