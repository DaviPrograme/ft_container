/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/08 01:14:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft {
template <typename Iterator>
class reverse_iterator {
	public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category 	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

	protected:
		iterator_type	_current;

	public:
		reverse_iterator(void): _current() {};
		explicit reverse_iterator(iterator_type it): _current(it) {};
		reverse_iterator(const reverse_iterator<Iterator> &other): _current(other._current) {}
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &other): _current(other.base()) {};
		~reverse_iterator(void) {};
		iterator_type base(void) const
		{ 
			return (this->_current); 
		}
		reference	operator[](difference_type n) const
		{
			return (this->base()[n - 1]);
		}
		reference	operator*(void) const
		{
			iterator_type temp = this->_current;
			return *(temp);
		}
		pointer		operator->(void) const
		{
			return &(operator*());
		}
		reverse_iterator& operator++(void)
		{
			this->_current--;
			return (*this);
		}
		reverse_iterator& operator--(void)
		{
			this->_current++;
			return (*this);
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			this->_current--;
			return (temp);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			this->_current++;
			return (temp);
		}
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(base() - n); }
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(base() + n); }
		reverse_iterator& operator+=(difference_type n)
		{
			this->_current -= n;
			return (*this);
		}
		reverse_iterator& operator-=(difference_type n)
		{
			this->_current += n;
			return (*this);
		}
	};
	template<class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<class IteratorL, class IteratorR>
	bool operator==(const reverse_iterator<IteratorR>& lhs, const reverse_iterator<IteratorL>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class IteratorL, class IteratorR>
	bool operator!=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class IteratorL, class IteratorR>
	bool operator<(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class IteratorL, class IteratorR>
	bool operator<=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class IteratorL, class IteratorR>
	bool operator>(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class IteratorL, class IteratorR>
	bool operator>=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<class Iterator>
	reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
	{
		return (it.base() - n);
	}

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	}
};
#endif