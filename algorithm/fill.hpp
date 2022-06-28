#ifndef ALGORITHM_FILL_HPP
#define ALGORITHM_FILL_HPP

namespace ft {

template<class FwdIt, class T>
void	fill(FwdIt first, FwdIt last, const T &x) {
	for (; first != last; ++first) {
		first = x;
	}
}

}

#endif // ALGORITHM_FILL_HPP
