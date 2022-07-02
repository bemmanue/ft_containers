#ifndef FT_CONTAINERS_TREE_TRAITS_HPP
#define FT_CONTAINERS_TREE_TRAITS_HPP

struct tree_traits {
	typedef T1			key_type;
	typedef T2			value_type;
	typedef T3			allocator_type;
	enum {Multi = <allow_equivalent_keys>};
	typedef T4			key_compare;
	typedef T5			value_compare;
	struct Kfn {
		const key_type& operator() (const value_type&) const;
	};
	key_compare			comp;
	tree_traits(key_compare);
};


#endif //FT_CONTAINERS_TREE_TRAITS_HPP
