/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/07 03:57:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_HPP
#define INTEGRAL_CONSTANT_HPP

namespace ft {
	template <class T, T v>
	struct integral_constant {
  		static const T value = v;
		typedef T value_type;
  		typedef integral_constant<T,v> type;
  		operator T() { return v; }
	};
};

#endif

		