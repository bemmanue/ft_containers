#ifndef FT_CONTAINERS_IS_INTEGRAL_HPP
#define FT_CONTAINERS_IS_INTEGRAL_HPP

#include <iostream>

namespace ft {

template <class T, bool v>
struct integral_constant {
	static const bool value = v;

	typedef T						value_type;
	typedef integral_constant<T, v>	type;

	operator value_type() const {
		return (value);
	}
};

template<class T>
struct is_integral						:	public std::integral_constant<T, false> {};

template<>
struct is_integral<bool>				:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<char>				:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<char16_t>			:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<char32_t> 			:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<wchar_t>				:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<signed char>			:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<short>				:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<int>					:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<long>				:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<long long>			:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<unsigned char>		:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<unsigned short>		:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<unsigned int>		:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<unsigned long>		:  public std::integral_constant<bool, true> {};

template<>
struct is_integral<unsigned long long>	:  public std::integral_constant<bool, true> {};

}

#endif //FT_CONTAINERS_IS_INTEGRAL_HPP
