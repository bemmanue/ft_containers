#ifndef VECTOR_OPERATOR_OVERLOADS_HPP
#define VECTOR_OPERATOR_OVERLOADS_HPP

#include "vector_base.hpp"

namespace ft {

template<class T, class Alloc> inline
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class T, class Alloc> inline
bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (!(lhs == rhs));
}

template<class T, class Alloc> inline
bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class T, class Alloc> inline
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (rhs < lhs);
}

template<class T, class Alloc> inline
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (!(rhs < lhs));
}

template<class T, class Alloc> inline
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	return (!(lhs < rhs));
}

}

#endif // VECTOR_OPERATOR_OVERLOADS_HPP
