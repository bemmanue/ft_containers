#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {

template<class T, class D, class P, class R, class P2, class R2>
class random_access_iterator: public iterator<random_access_iterator_tag, T, D, P, R> {
	public:
		typedef random_access_iterator<T, D, P, R, P2, R2>	iterator;
		typedef typename iterator::difference_type 			difference_type;
		typedef typename iterator::pointer 					pointer;
		typedef typename iterator::reference 				reference;


		random_access_iterator() {}

		random_access_iterator(const random_access_iterator<T, D, P, R, P2, R2>& iterator)
				: current(iterator.base()) {}


		template <class _T, class _D, class _P, class _R, class _P2, class _R2>
		random_access_iterator(const random_access_iterator<_T, _D, _P, _R, _P2, _R2>& iterator)
				: current(iterator.base()) {}


		explicit random_access_iterator(P2 pointer)
				: current(pointer) {}


		pointer base() const {
			return (current);
		}

		reference operator* () const {
			return *current;
		}

		random_access_iterator& operator= (const iterator& a) {
			current = a.current;
			return *this;
		}

		random_access_iterator& operator+= (difference_type n) {
			current += n;
			return *this;
		}

		iterator& operator++ () {
			current++;
			return *this;
		}

		iterator operator++ (int) {
			iterator temp = *this;
			++current;
			return temp;
		}

		iterator operator+ (difference_type n) {
			iterator temp = *this;
			return (temp += n);
		}

		iterator& operator-= (difference_type n) {
			current -= n;
			return *this;
		}

		iterator& operator-- () {
			--current;
			return *this;
		}

		iterator operator-- (int) {
			iterator temp = *this;
			current--;
			return temp;
		}

		iterator operator- (difference_type n) const {
			iterator temp = *this;
			return (temp -= n);
		}

		difference_type operator- (const iterator& a) const {
			return (current - a.current);
		}

		reference operator[] (D n) const {
			return *(current + n);
		}

		bool operator< (const iterator& b) const {
			return (current < b.current);
		}

		bool operator> (const iterator& b) const {
			return (current > b.current);
		}

		bool operator<= (const iterator& b) const {
			return (current <= b.current);
		}

		bool operator>= (const iterator& b) const {
			return (current >= b.current);
		}

		bool operator== (const iterator& b) const {
			return (current == b.current);
		}

		bool operator!= (const iterator& b) const {
			return (current != b.current);
		}

	protected:
		pointer	current;
};

template<class T, class D, class P, class R, class P2, class R2> inline
random_access_iterator<T, D, P, R, P2, R2> operator+ (D n, const random_access_iterator<T, D, P, R, P2, R2>& y) {
	return (y + n);
}

}

#endif // RANDOM_ACCESS_ITERATOR_HPP
