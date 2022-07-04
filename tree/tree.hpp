#ifndef FT_CONTAINERS_TREE_HPP
#define FT_CONTAINERS_TREE_HPP

#include "../iterator/iterator.hpp"
#include "tree_value.hpp"
#include "tree_iterator.hpp"

namespace ft {

template<class T>
class tree : public tree_value<T> {

	public:
		typedef tree<T>										Myt;
		typedef tree_value<T>								Mybase;
		typedef typename T::key_type						key_type;
		typedef typename T::key_compare						key_compare;
		typedef typename T::value_compare					value_compare;
		typedef typename T::value_type						value_type;
		typedef	typename T::allocator_type					allocator_type;

	protected:
		typedef typename tree_nod<T>::genptr				genptr;
		typedef typename tree_nod<T>::node					node;

		enum Redbl {
			Red,
			Black
		};

		typedef typename allocator_type::template
				rebind<node>::other::pointer				nodeptr;
		typedef typename allocator_type::template
				rebind<nodeptr>::other::reference			nodepref;
		typedef typename allocator_type::template
				rebind<key_type>::other::const_reference	keyref;
		typedef typename allocator_type::template
				rebind<char>::other::reference				charref;
		typedef typename allocator_type::template
				rebind<value_type>::other::reference		vref;


		static charref color(nodeptr P) {
			return ((charref)(*P).color);
		}
		static charref isnil(nodeptr P) {
			return ((charref)(*P).isnil);
		}
		static keyref key(nodeptr P) {
			return (Kfn()(value(P)));
		}
		static nodepref left(nodeptr P) {
			return ((nodepref)(*P).left);
		}
		static nodepref parent(nodeptr P) {
			return ((nodepref)(*P).parent);
		}
		static nodepref right(nodeptr P) {
			return ((nodepref)(*P).right);
		}
		static vref value(nodeptr P) {
			return ((vref)(*P).value);
		}

	public:
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	dift;
		typedef dift										difference_type;
		typedef typename allocator_type::template
				rebind<value_type>::other::pointer			tptr;
		typedef typename allocator_type::template
				rebind<value_type>::other::const_pointer	ctptr;
		typedef typename allocator_type::template
				rebind<value_type>::other::reference		reft;
		typedef tptr 										pointer;
		typedef ctptr										const_pointer;
		typedef reft 										reference;
		typedef typename allocator_type::template
				rebind<value_type>::other::const_reference	const_reference;


		class tree_iterator;
		friend class tree_iterator;
		class tree_iterator : public ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> {

			public:
				typedef ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, tptr, reft> Mybase;
				typedef typename Mybase::iterator_category	iterator_category;
				typedef typename Mybase::value_type 		value_type;
				typedef typename Mybase::difference_type 	difference_type;
				typedef typename Mybase::pointer 			pointer;
				typedef typename Mybase::reference 			reference;

			tree_iterator() : ptr(0) {}
			tree_iterator(nodeptr P) : ptr(P) {}

			reference operator*() const {}
			tptr operator->() const {}
			tree_iterator& operator++() {}
			tree_iterator operator++(int) {}
			tree_iterator& operator--() {}
			tree_iterator operator--(int) {}
			bool operator==(const tree_iterator x) const {}
			bool operator!=(const tree_iterator x) const {}
			void dec() {}
			void Inc() {}
			nodeptr mynode() const {}

			protected:
				nodeptr ptr;
		};

		class tree_const_iterator;
		friend class tree_const_iterator;
		class tree_const_iterator : public ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, ctptr, const_reference> {

			public:
				typedef ft::tree_iterator<bidirectional_iterator_tag, value_type, dift, ctptr, const_reference> Mybase;
				typedef typename Mybase::iterator_category	iterator_category;
				typedef typename Mybase::value_type 		value_type;
				typedef typename Mybase::difference_type 	difference_type;
				typedef typename Mybase::pointer 			pointer;
				typedef typename Mybase::reference 			reference;

				tree_const_iterator() : ptr(0) {}
				tree_const_iterator(nodeptr P) : ptr(P) {}
				tree_const_iterator(const typename tree<T>::iterator& x) : ptr(x.mynode()) {}

				const_reference operator*() const {}
				tptr operator->() const {}
				tree_const_iterator& operator++() {}
				tree_const_iterator operator++(int) {}
				tree_const_iterator& operator--() {}
				tree_const_iterator operator--(int) {}
				bool operator==(const tree_iterator x) const {}
				bool operator!=(const tree_iterator x) const {}
				void dec() {}
				void Inc() {}
				nodeptr mynode() const {}

			protected:
				nodeptr ptr;
		};

		typedef std::reverse_iterator<tree_iterator> 				reverse_iterator;
		typedef std::reverse_iterator<tree_const_iterator>			const_reverse_iterator;
		typedef ft::pair<tree_iterator, bool>						pairib;
		typedef ft::pair<tree_iterator, tree_iterator>				pairii;
		typedef ft::pair<tree_const_iterator, tree_const_iterator>	paircc;

		//constructors
		explicit tree(const key_compare& parg, const allocator_type& Al);
		tree(const value_type *F, const value_type *L, const key_compare& parg, const allocator_type& Al);
		tree(const Myt& x);
		~tree();
		Myt& operator=(const Myt& x);

		//iterators
		tree_iterator		begin();
		tree_const_iterator	begin() const;
		tree_iterator		end();
		tree_const_iterator end() const;
		tree_iterator 		rbegin();
		tree_const_iterator rbegin() const;
		tree_iterator 		rend();
		tree_const_iterator rend() const;

		//capasity
		size_type			size() const;
		size_type			max_size() const;
		bool				empty() const;

	//	key_compare			key_comp() const;
	//	value_compare		value_comp() const;
	//	allocator_type		get_allocator() const;

		//modifiers
		pairib				insert(const value_type& v);
		tree_iterator		insert(tree_iterator P, const value_type& v);
		template<class It>
		void 				insert(It F, It L);
		tree_iterator		erase(tree_iterator P);
		tree_iterator		erase(tree_iterator F, tree_iterator L);
		size_type 			erase(const key_type& x);
		void 				erase(const key_type *F, const key_type *L);
		void				clear();

		tree_iterator		find(const key_type& Kv);
		tree_const_iterator	find(const key_type& Kv) const;
		size_type			count(const key_type& Kv) const;
		tree_iterator		lower_bound(const key_type& Kv);
		tree_const_iterator	lower_bound(const key_type& Kv) const;
		tree_iterator		upper_bound(const key_type& Kv);
		tree_const_iterator	upper_bound(const key_type& Kv) const;
		pairii				equal_range(const key_type& Kv);
		paircc				equal_range(const key_type& Kv) const;
		void				swap(Myt& x);

	protected:
		void			Copy(const Myt& x);
		nodeptr			Copy(nodeptr x, nodeptr p);
		void			Erase(nodeptr x);
		void			Init();
		tree_iterator	insert(bool Addleft, nodeptr Y, const value_type& v);
		nodeptr 		Lbound(const key_type& Kv) const;
		nodeptr& 		Lmost();
		nodeptr& 		Lmost() const;
		void			Lrotate(nodeptr x);
		static nodeptr	Max(nodeptr P);
		static nodeptr	Min(nodeptr P);
		nodeptr&		Rmost();
		nodeptr&		Rmost() const;
		nodeptr&		Root();
		nodeptr&		Root() const;
		void 			Rrotate(nodeptr x);
		nodeptr			Ubound(const key_type& Kv) const;
		nodeptr			Buynode(nodeptr parg, char Carg);
		void			Consval(tptr P, const value_type& V);
		void			Destval(tptr P);
		void			Freenode(nodeptr S);

		nodeptr			Head;
		size_type		Size;
};

}

#endif //FT_CONTAINERS_TREE_HPP
