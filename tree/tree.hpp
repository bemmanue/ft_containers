#ifndef FT_CONTAINERS_TREE_HPP
#define FT_CONTAINERS_TREE_HPP

#include "../iterator/iterator.hpp"
#include "tree_value.hpp"
#include "tree_iterator.hpp"
#include "const_tree_iterator.hpp"

namespace ft {

template<class Tree_traits>
class tree : public tree_value<Tree_traits> {

	public:
		typedef tree<Tree_traits>							Myt;
		typedef tree_value<Tree_traits>						Mybase;
		typedef typename Tree_traits::key_type				key_type;
		typedef typename Tree_traits::key_compare			key_compare;
		typedef typename Tree_traits::value_compare			value_compare;
		typedef typename Tree_traits::value_type			value_type;
		typedef	typename Tree_traits::allocator_type		allocator_type;

	protected:
		typedef typename tree_nod<Tree_traits>::genptr		genptr;
		typedef typename tree_nod<Tree_traits>::node		node;

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
		typedef typename allocator_type::size_type					size_type;
		typedef typename allocator_type::difference_type			difference_type;
		typedef typename allocator_type::template
				rebind<value_type>::other::pointer					pointer;
		typedef typename allocator_type::template
				rebind<value_type>::other::const_pointer			const_pointer;
		typedef typename allocator_type::template
				rebind<value_type>::other::reference				reference;
		typedef typename allocator_type::template
				rebind<value_type>::other::const_reference			const_reference;

		class tree_iterator;
		class const_tree_iterator;

		typedef ft::reverse_iterator<tree_iterator> 				reverse_iterator;
		typedef ft::reverse_iterator<const_tree_iterator>			const_reverse_iterator;
		typedef ft::pair<tree_iterator, bool>						pairib;
		typedef ft::pair<tree_iterator, tree_iterator>				pairii;
		typedef ft::pair<const_tree_iterator, const_tree_iterator>	paircc;



		//constructors
		explicit tree(const key_compare& parg, const allocator_type& Al);
		tree(const value_type *F, const value_type *L, const key_compare& parg, const allocator_type& Al);
		tree(const Myt& x);
		~tree();
		Myt& operator=(const Myt& x);
		allocator_type get_allocator() const;

		//iterators
		tree_iterator		begin();
		const_tree_iterator	begin() const;
		tree_iterator		end();
		const_tree_iterator end() const;
		tree_iterator 		rbegin();
		const_tree_iterator rbegin() const;
		tree_iterator 		rend();
		const_tree_iterator rend() const;

		//capacity
		bool				empty() const;
		size_type			size() const;
		size_type			max_size() const;

		//modifiers
		void				clear();
		pairib				insert(const value_type& v);
		tree_iterator		insert(tree_iterator P, const value_type& v);
		template<class It>
		void 				insert(It F, It L);
		tree_iterator		erase(tree_iterator P);
		tree_iterator		erase(tree_iterator F, tree_iterator L);
		size_type 			erase(const key_type& x);
		void 				erase(const key_type *F, const key_type *L);
		void				swap(Myt& x);

		// lookup
		size_type			count(const key_type& Kv) const;
		tree_iterator		find(const key_type& Kv);
		const_tree_iterator	find(const key_type& Kv) const;
		pairii				equal_range(const key_type& Kv);
		paircc				equal_range(const key_type& Kv) const;
		tree_iterator		lower_bound(const key_type& Kv);
		const_tree_iterator	lower_bound(const key_type& Kv) const;
		tree_iterator		upper_bound(const key_type& Kv);
		const_tree_iterator	upper_bound(const key_type& Kv) const;

		//observers
		key_compare			key_comp() const;
		value_compare		value_comp() const;

	protected:
		void			Copy(const Myt& x);
		nodeptr			Copy(nodeptr x, nodeptr p);
		void			Erase(nodeptr x);
		void			Init();
		tree_iterator	Insert(bool Addleft, nodeptr Y, const value_type& v);
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
		void			Consval(pointer P, const value_type& V);
		void			Destval(pointer P);
		void			Freenode(nodeptr S);

		nodeptr			Head;
		size_type		Size;
};

}

#endif //FT_CONTAINERS_TREE_HPP
