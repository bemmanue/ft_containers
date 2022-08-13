#ifndef UTILITY_IS_INTEGRAL_HPP
#define UTILITY_IS_INTEGRAL_HPP

#include <iostream>
#include <cstddef>

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
struct is_integral						:	public integral_constant<T, false> {};

template<>
struct is_integral<bool>				:  public integral_constant<bool, true> {};

template<>
struct is_integral<char>				:  public integral_constant<bool, true> {};

template<>
struct is_integral<wchar_t>				:  public integral_constant<bool, true> {};

template<>
struct is_integral<signed char>			:  public integral_constant<bool, true> {};

template<>
struct is_integral<short>				:  public integral_constant<bool, true> {};

template<>
struct is_integral<int>					:  public integral_constant<bool, true> {};

template<>
struct is_integral<long>				:  public integral_constant<bool, true> {};

template<>
struct is_integral<long long>			:  public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned char>		:  public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned short>		:  public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned int>		:  public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned long>		:  public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned long long>	:  public integral_constant<bool, true> {};

}

#endif //UTILITY_IS_INTEGRAL_HPP
