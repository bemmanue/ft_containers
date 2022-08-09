#ifndef ALGORITHM_FILL_HPP
#define ALGORITHM_FILL_HPP

namespace ft {

template<class FwdIt, class T>
void	fill(FwdIt first, FwdIt last, const T& x) {
	for (; first != last; ++first) {
		*first = x;
	}
}

template <class OutIt, class Size, class T> inline
void fill_n(OutIt first, Size n,  const T& x) {
	for (; 0 < n ; --n, ++first) {
		*first = x;
	}
}

}

#endif // ALGORITHM_FILL_HPP
