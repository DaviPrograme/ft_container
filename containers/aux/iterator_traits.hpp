/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/05 03:03:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {
	
	template <class T>
	struct iterator_traits {
		typedef typename T::value_type			value_type;
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::ptrdiff_t					difference_type;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::ptrdiff_t					difference_type;
	};

};

#endif

		