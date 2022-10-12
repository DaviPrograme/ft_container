/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/07 04:02:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP
# include "integral_constant.hpp"

namespace ft {
	template<class T> struct is_integral: public integral_constant<bool, false> {};
	template<> struct is_integral<bool>: public integral_constant<bool, true> {};
	template<> struct is_integral<char>: public integral_constant<bool, true> {};
	template<> struct is_integral<wchar_t>: public integral_constant<bool, true> {};
	template<> struct is_integral<signed char>: public integral_constant<bool, true> {};
	template<> struct is_integral<short int>: public integral_constant<bool, true> {};
	template<> struct is_integral<int>: public integral_constant<bool, true> {};
	template<> struct is_integral<long int>: public integral_constant<bool, true> {};
	template<> struct is_integral<long long int>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned char>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned short int>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned int>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned long int>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned long long int>: public integral_constant<bool, true> {};
};

#endif

		