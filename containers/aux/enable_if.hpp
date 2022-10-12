/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/07 03:40:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft {
	template <bool Cond, class T = void>
	struct enable_if {};
	
	template <class T>
	struct enable_if<true, T> {typedef T type;};
};

#endif

		