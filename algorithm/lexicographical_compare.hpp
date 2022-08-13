#ifndef ALGORITHM_LEXICOGRAPHICAL_COMPARE_HPP
#define ALGORITHM_LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {

template <class InIt1, class InIt2>
inline bool lexicographical_compare(InIt1 first, InIt1 last, InIt2 _first, InIt2 _last) {
	for (; first != last && _first != _last; ++first, ++_first) {
		if (*first < *_first) {
			return true;
		} else if (*_first < *first) {
			return false;
		}
	}
	return first == last && _first != _last;
}

template <class InIt1, class InIt2, class Compare>
inline bool lexicographical_compare(InIt1 first, InIt1 last, InIt2 _first, InIt2 _last, Compare p) {
	for (; first != last && _first != _last; ++first, ++_first) {
		if (p(*first, *_first)) {
			return true;
		}
		if (p(*_first, *first)) {
			return false;
		}
	}
	return first == last && _first != _last;
}

}

#endif //ALGORITHM_LEXICOGRAPHICAL_COMPARE_HPP
