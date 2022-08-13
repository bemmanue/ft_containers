#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_base.hpp"
#include "iterator_tags.hpp"

namespace ft {

template<class T, class D, class P, class R, class P2, class R2>
class random_access_iterator: public ft::iterator<random_access_iterator_tag, T, D, P, R> {
	public:
		typedef random_access_iterator<T, D, P, R, P2, R2>		Myt;
		typedef typename Myt::difference_type 		difference_type;
		typedef typename Myt::pointer 				pointer;
		typedef typename Myt::reference 				reference;

		random_access_iterator() {}

		random_access_iterator(const ft::random_access_iterator<T, D, P, R, P2, R2>& x)
				: current(x.base()) {}

		template <class _T, class _D, class _P, class _R, class _P2, class _R2>
		random_access_iterator(const random_access_iterator<_T, _D, _P, _R, _P2, _R2>& iterator)
				: current(iterator.base()) {}

		explicit random_access_iterator(pointer p)
				: current(p) {}

		pointer base() const {
			return current;
		}

		reference operator*() const {
			return *current;
		}

		pointer operator->() const {
			return &**this;
		}

		random_access_iterator& operator=(const random_access_iterator& other) {
			current = other.current;
			return *this;
		}

		random_access_iterator& operator+=(difference_type n) {
			current += n;
			return *this;
		}

		Myt& operator++() {
			current++;
			return *this;
		}

		Myt operator++(int) {
			Myt temp = *this;
			++current;
			return temp;
		}

		Myt operator+(difference_type n) {
			Myt temp = *this;
			return (temp += n);
		}

		Myt& operator-=(difference_type n) {
			current -= n;
			return *this;
		}

		Myt& operator--() {
			--current;
			return *this;
		}

		Myt operator--(int) {
			Myt temp = *this;
			current--;
			return temp;
		}

		Myt operator-(difference_type n) const {
			Myt temp = *this;
			return (temp -= n);
		}

		difference_type operator-(const Myt& a) const {
			return (current - a.current);
		}

		reference operator[](D n) const {
			return *(current + n);
		}

		bool operator<(const Myt& b) const {
			return (current < b.current);
		}

		bool operator>(const Myt& b) const {
			return (current > b.current);
		}

		bool operator<=(const Myt& b) const {
			return (current <= b.current);
		}

		bool operator>=(const Myt& b) const {
			return (current >= b.current);
		}

		bool operator==(const Myt& b) const {
			return (current == b.current);
		}

		bool operator!=(const Myt& b) const {
			return (current != b.current);
		}

	protected:
		pointer	current;
};

template<class T, class D, class P, class R, class P2, class R2> inline
random_access_iterator<T, D, P, R, P2, R2> operator+(D n, const random_access_iterator<T, D, P, R, P2, R2>& y) {
	return (y + n);
}

}

#endif //RANDOM_ACCESS_ITERATOR_HPP
