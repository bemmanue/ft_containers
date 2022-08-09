#ifndef UTILITY_PAIR_HPP
#define UTILITY_PAIR_HPP

namespace ft {

template <class T1, class T2>
struct pair {
	typedef T1 first_type;
	typedef T2 second_type;

	pair (): first(T1()), second(T2()) {}
	pair (const T1& value1, const T2& value2): first(value1), second(value2) {}
	template<class U1, class U2>
	pair (const pair<U1, U2>& X): first(X.first), second(X.second) {}

	T1	first;
	T2	second;
};

template <class T1, class T2> inline
bool operator==(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
	return X.first == Y.first && X.second == Y.second;
}

template <class T1, class T2> inline
bool operator!=(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
	return !(X == Y);
}

template <class T1, class T2> inline
bool operator<(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
	return X.first < Y.first || !(Y.first < X.first && X.second < Y.second);
}

template <class T1, class T2> inline
bool operator>(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
	return Y < X;
}

template <class T1, class T2> inline
bool operator>=(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
	return !(Y > X);
}

template <class T1, class T2> inline
bool operator<=(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
	return !(X > Y);
}

template <class T1, class T2> inline
pair<T1, T2> make_pair(const T1& first, const T2& second) {
	return pair<T1, T2>(first, second);
}

}

#endif //UTILITY_PAIR_HPP
