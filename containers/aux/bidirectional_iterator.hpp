/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/09/05 11:33:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP
#include "AVL.hpp"

namespace ft {

	template <typename T, typename Alloc, typename Compare>
	class bidirectional_iterator
	{
		public:
			typedef	bidirectional_iterator<T, Alloc, Compare>		iterator;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::ptrdiff_t					difference_type;
			typedef bidirectional_iterator<const T, Alloc, Compare>	const_iterator;

		private:
			typedef Node<T>							node;

		private:
			typedef AVL<T, Alloc, Compare> avl_type;
			Compare _less;
			node	*_node;
			avl_type *_avl;
			bool _nullAtTheEnd;
			

		private:
			node *next(node *ptr){
				node *aux;
				if (!ptr){
					if (_nullAtTheEnd)
						return _avl->max();
					return _avl->min();
				}
				if (ptr->_right)
					return min(ptr->_right);
				node *parent = ptr->_parent;
				while(parent && _less(parent->_pair->first, ptr->_pair->first)){
					aux = parent->_parent;
					parent = aux;
				}
				return parent;
			}
			node *previous(node *ptr){
				node *aux;
				if (!ptr)
					return _avl->max();
				if (ptr->_left)
					return max(ptr->_left);
				node *parent = ptr->_parent;
				while(parent &&  _less(ptr->_pair->first, parent->_pair->first)){
					aux = parent->_parent;
					parent = aux;
				}
				return parent;
			}
			node *max(node *node){
				if (!node || !(node->_right))
					return node;
				return max(node->_right);
			}
			node *min(node *node){
				if (!node || !(node->_left))
					return node;
				return min(node->_left);
			}
		public:
			bidirectional_iterator(): _node(NULL), _avl(NULL) {}
			explicit bidirectional_iterator(node *ptr, avl_type *avl, bool nullEnd = true): _node(ptr), _avl(avl), _nullAtTheEnd(nullEnd) {}
			bidirectional_iterator(const bidirectional_iterator& instance) {*this = instance;}
			~bidirectional_iterator() {}
			bidirectional_iterator& operator=(const bidirectional_iterator& right_hand_side){
				this->_node = right_hand_side._node;
				this->_avl = right_hand_side._avl;
				this->_nullAtTheEnd = right_hand_side._nullAtTheEnd;
				return *this;
			}
			iterator& operator++(void){
				this->_node = next(this->_node);
				return (*this);
			}
			iterator& operator--(void){
				this->_node = previous(this->_node);
				return (*this);
			}
			iterator operator++(int){
				iterator copy(*this);
				this->_node = next(this->_node);
				return (copy);
			}
			iterator operator--(int){
				iterator copy(*this);
				this->_node = previous(this->_node);
				return (copy);
			}
			

			bool operator==(const iterator& right_hand_side){
				return this->_node == right_hand_side._node;
			}
			bool operator!=(const iterator& right_hand_side){
				return this->_node != right_hand_side._node;
			}
			bool operator>(const iterator& right_hand_side){
				return this->_node > right_hand_side._node;
			}
			bool operator>=(const iterator& right_hand_side){
				return this->_node >= right_hand_side._node;
			}
			bool operator<(const iterator& right_hand_side){
				return this->_node < right_hand_side._node;
			}
			bool operator<=(const iterator& right_hand_side){
				return this->_node <= right_hand_side._node;
			}
			reference	operator*() {return *(this->_node->_pair);}
			pointer 	operator->() {return (&operator*());} 
	};
}

#endif