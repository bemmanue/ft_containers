#ifndef TREE_BASE_HPP
#define TREE_BASE_HPP

#include "../utility/utility.hpp"
#include "../iterator/iterator.hpp"
#include "tree_value.hpp"
#include "tree_node.hpp"

namespace ft {

template<class Tree_traits>
class tree : public ft::tree_value<Tree_traits> {

	public:
		typedef tree<Tree_traits>							Myt;
		typedef tree_value<Tree_traits>						Mybase;
		typedef typename Tree_traits::key_type				key_type;
		typedef typename Tree_traits::key_compare			key_compare;
		typedef typename Tree_traits::value_compare			value_compare;
		typedef typename Tree_traits::value_type			value_type;
		typedef	typename Tree_traits::allocator_type		allocator_type;

	protected:
		typedef typename ft::tree_node<Tree_traits>::Genptr	Genptr;
		typedef typename ft::tree_node<Tree_traits>::Node	Node;

		enum	Redbl {Red, Black};

		typedef typename allocator_type::template
		        rebind<Node>::other::pointer				Nodeptr;
		typedef typename allocator_type::template
		        rebind<Nodeptr>::other::reference			Noderef;
		typedef typename allocator_type::template
		        rebind<key_type>::other::const_reference	Keyref;
		typedef typename allocator_type::template
		        rebind<char>::other::reference				Charref;
		typedef typename allocator_type::template
		        rebind<value_type>::other::reference		Vref;

		static Charref	Color(Nodeptr P)	{ return ((Charref)(*P).Color); 			}
		static Charref	Isnil(Nodeptr P)	{ return ((Charref)(*P).Isnil);				}
		static Keyref	Key(Nodeptr P)		{ return (Tree_traits::GetKey(Value(P)));	}
		static Noderef	Left(Nodeptr P)		{ return ((Noderef)(*P).Left);				}
		static Noderef	Right(Nodeptr P)	{ return ((Noderef)(*P).Right);				}
		static Noderef	Parent(Nodeptr P)	{ return ((Noderef)(*P).Parent);			}
		static Vref		Value(Nodeptr P)	{ return ((Vref)(*P).Value);				}

	public:
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	Dift;
		typedef typename allocator_type::template
		        rebind<value_type>::other::pointer			Tptr;
		typedef typename allocator_type::template
		        rebind<value_type>::other::const_pointer	Ctptr;
		typedef typename allocator_type::template
		        rebind<value_type>::other::reference		Reft;
		typedef typename allocator_type::template
		        rebind<value_type>::other::const_reference	const_reference;

		typedef	Dift										difference_type;
		typedef Tptr										pointer;
		typedef Ctptr										const_pointer;
		typedef Reft										reference;

		//Iterator
		class	        iterator;
		friend class	tree<Tree_traits>::iterator;
		class iterator : public ft::iterator<bidirectional_iterator_tag, value_type, Dift, Tptr, Reft> {
			private:
				void Dec() {
					if (Isnil(current_)) {
						current_ = Right(current_);
					} else if (!Isnil(Left(current_))) {
						current_ = Max(Left(current_));
					} else {
						Nodeptr P;
						while (!Isnil(P = Parent(current_)) && current_ == Left(P))
							current_ = P;
						if (!Isnil(P))
							current_ = P;
					}
				}

				void Inc() {
					if (Isnil(current_)) {
						;
					} else if (!Isnil(Right(current_))) {
						current_ = Min(Right(current_));
					} else {
						Nodeptr P;
						while (!Isnil(P = Parent(current_)) && current_ == Right(P))
							current_ = P;
						current_ = P;
					}
				}

			protected:
				Nodeptr current_;

			public:
				typedef ft::iterator<ft::bidirectional_iterator_tag,
					value_type, Dift, Tptr, Reft>						Mybase;
				typedef typename Mybase::iterator_category				iterator_category;
//				typedef typename Mybase::value_type						value_type;
				typedef typename Mybase::difference_type				difference_type;
				typedef typename Mybase::pointer						pointer;
				typedef typename Mybase::reference						reference;

				iterator() : current_(0) {}

				iterator(Nodeptr P) : current_(P) {}


				reference operator*() const {
					return Value(current_);
				}

				Tptr operator->() const {
					return &**this;
				}

				iterator operator++() {
					Inc();
					return *this;
				}

				iterator operator++(int) {
					iterator tmp = *this;
					++*this;
					return tmp;
				}

				iterator operator--() {
					Dec();
					return *this;
				}

				iterator operator--(int) {
					iterator tmp = *this;
					--*this;
					return tmp;
				}

				bool operator==(const iterator &X) const {
					return current_ == X.current_;
				}

				bool operator!=(const iterator &X) const {
					return !(*this == X);
				}

				Nodeptr Mynode() const {
					return current_;
				}
		};

		//Const_iterator
		class	        const_iterator;
		friend class	tree<Tree_traits>::const_iterator;
		class const_iterator : public ft::iterator<bidirectional_iterator_tag, value_type, Dift, Ctptr, const_reference> {
			private:
				void Dec() {
					if (Isnil(current_)) {
						current_ = Right(current_);
					} else if (!Isnil(Left(current_))) {
						current_ = Max(Left(current_));
					} else {
						Nodeptr P;
						while (!Isnil(P = Parent(current_)) && current_ == Left(P))
							current_ = P;
						if (!Isnil(P))
							current_ = P;
					}
				}

				void Inc() {
					if (Isnil(current_)) {
						;
					} else if (!Isnil(Right(current_))) {
						current_ = Min(Right(current_));
					} else {
						Nodeptr P;
						while (!Isnil(P = Parent(current_)) && current_ == Right(P))
							current_ = P;
						current_ = P;
					}
				}

			protected:
				Nodeptr	current_;

			public:
				typedef	ft::iterator<ft::bidirectional_iterator_tag,
					value_type, Dift, Ctptr, const_reference>			Mybase;
				typedef typename Mybase::iterator_category				iterator_category;
//				typedef typename Mybase::value_type						value_type;
				typedef typename Mybase::difference_type				difference_type;
				typedef typename Mybase::pointer						pointer;
				typedef typename Mybase::reference						reference;

				const_iterator() : current_(0) {}

				const_iterator(Nodeptr P) : current_(P) {}

				const_iterator(const typename tree<Tree_traits>::iterator& X): current_(X.Mynode()) {}

				template <class TreeTraits1>
				const_iterator(const typename tree<TreeTraits1>::const_iterator& X) {
					current_ = reinterpret_cast<Nodeptr>(X.current_);
				}

				const_reference   operator*() const {
					return Value(current_);
				}

				Ctptr    operator->() const {
					return &**this;
				}

				const_iterator&	operator++() {
					Inc();
					return *this;
				}

				const_iterator	operator++(int) {
					const_iterator tmp = *this;
					++*this;
					return tmp;
				}

				const_iterator&	operator--() {
					Dec();
					return *this;
				}

				const_iterator	operator--(int) {
					const_iterator	tmp = *this;
					--*this;
					return tmp;
				}

				bool operator==(const const_iterator& X) const {
					return current_ == X.current_;
				}

				bool operator!=(const const_iterator& X) const {
					return !(*this == X);
				}

				Nodeptr	Mynode() const {
					return current_;
				}
		};


		typedef ft::reverse_iterator<iterator> 					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		typedef	ft::pair<iterator, bool>						Pairib;
		typedef	ft::pair<iterator, iterator>					Pairii;
		typedef	ft::pair<const_iterator, const_iterator>		Paircc;

		//Constructors
		explicit tree(const key_compare& parg, const allocator_type& Al);
		tree(const value_type *F, const value_type *L, const key_compare& parg, const allocator_type& Al);
		tree(const Myt& x);
		~tree();
		Myt& operator=(const Myt& x);
		allocator_type get_allocator() const;

		//iterators
		iterator					begin();
		const_iterator				begin() const;
		iterator					end();
		const_iterator 				end() const;
		reverse_iterator 			rbegin();
		const_reverse_iterator 		rbegin() const;
		reverse_iterator 			rend();
		const_reverse_iterator 		rend() const;

		//Capacity
		bool				empty() const;
		size_type			size() const;
		size_type			max_size() const;

		//Modifiers
		void				clear();
		Pairib				insert(const value_type& v);
		iterator			insert(iterator P, const value_type& v);
		template<class It>
		void 				insert(It F, It L);
		iterator			erase(iterator P);
		iterator			erase(iterator F, iterator L);
		size_type 			erase(const key_type& x);
		void 				erase(const key_type *F, const key_type *L);
		void				swap(Myt& x);

		//Lookup
		size_type			count(const key_type& Kv) const;
		iterator			find(const key_type& Kv);
		const_iterator		find(const key_type& Kv) const;
		Pairii				equal_range(const key_type& Kv);
		Paircc				equal_range(const key_type& Kv) const;
		iterator			lower_bound(const key_type& Kv);
		const_iterator		lower_bound(const key_type& Kv) const;
		iterator			upper_bound(const key_type& Kv);
		const_iterator		upper_bound(const key_type& Kv) const;

		//Observers
		key_compare			key_comp() const;
		value_compare		value_comp() const;

	protected:
		//Member functions
		void				Copy(const Myt& x);
		Nodeptr				Copy(Nodeptr x, Nodeptr p);
		void				Erase(Nodeptr x);
		void				Init();
		iterator			Insert(bool Addleft, Nodeptr Y, const value_type& v);
		Nodeptr 			Lbound(const key_type& Kv) const;
		Nodeptr& 			Lmost();
		Nodeptr& 			Lmost() const;
		void				Lrotate(Nodeptr x);
		static Nodeptr		Max(Nodeptr P);
		static Nodeptr		Min(Nodeptr P);
		Nodeptr&			Rmost();
		Nodeptr&			Rmost() const;
		Nodeptr&			Root();
		Nodeptr&			Root() const;
		void 				Rrotate(Nodeptr x);
		Nodeptr				Ubound(const key_type& Kv) const;
		Nodeptr				Buynode(Nodeptr parg, char Carg);
		void				Consval(pointer P, const value_type& V);
		void				Destval(pointer P);
		void				Freenode(Nodeptr S);

		//Member objects
		Nodeptr				Head;
		size_type			Size;
};

}

#endif //TREE_BASE_HPP
