#ifndef SET_TRAITS_HPP
#define SET_TRAITS_HPP

namespace ft {

template <class Key, class Pred, class Allocator>
class set_traits {
	public:
		typedef Key								key_type;
		typedef Key								value_type;
		typedef Pred							key_compare;
		typedef typename Allocator::template
			rebind<value_type>::other			allocator_type;

		set_traits() : comp() {}
		explicit set_traits(Pred Parg) : comp(Parg) {}

		typedef key_compare						value_compare;

		const static Key &GetKey(const value_type& v) {
			Kfn	ret;
			return ret(v);
		}

		struct Kfn {
			const Key& operator()(const value_type& x) const {
				return x;
			}
		};

		Pred	comp;
};

}

#endif //SET_TRAITS_HPP
