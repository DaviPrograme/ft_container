/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/21 03:27:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
#define AVL_HPP

#include "pair.hpp"
#include <utility>
#include <cmath>
#include "bidirectional_iterator.hpp"

template<class T>
class Node{
	
	public: typedef T pair_type;
	
	public:
		pair_type  *_pair;
		size_t _height;
		Node *_parent;
		Node *_right;
		Node *_left;

	public:	
		Node(): _pair(NULL), _height(0), _parent(NULL), _right(NULL), _left(NULL){};
		Node(pair_type &data): _pair(data), _height(1), _parent(NULL), _right(NULL), _left(NULL){};
		Node(Node const &copy){
			this->_pair = copy._pair;
		}
		~Node(){};
};

template<class T, class AllocPair, class Compare>
class AVL {
	public:
		typedef T pair_type;
		typedef Node<T> node_type;
		typedef Compare key_compare;
		typedef AllocPair alloc_pair;
		typedef std::allocator< node_type > n_alloc;
		node_type *_root;
		size_t _size;
		n_alloc _alloc;
		alloc_pair _alloc_pair;
		key_compare _less;
	
	template<typename Key>
	bool areKeysEqual(Key key1, Key key2){
		return !this->_less(key1, key2) && !this->_less(key2, key1);
	}
		
	AVL(): _root(NULL), _size(0) {};
	node_type *upperBound(pair_type pair){
		node_type *element = this->findApproximate(pair);
		node_type *aux2;
		if(element && areKeysEqual(element->_pair->first, pair.first) && element->_right)
			return min(&element->_right); 
		while(element && (_less(element->_pair->first, pair.first) || areKeysEqual(element->_pair->first, pair.first))){
			aux2 = element->_parent;
			element = aux2;
		}
		return element;
	}
	node_type *lowerBound(pair_type pair){
		node_type *element = findApproximate(pair);
		node_type *aux2;
		while(element && _less(element->_pair->first, pair.first)){
			aux2 = element->_parent;
			element = aux2;
		}
		return element;
	}
	~AVL(){
		freeTreeAVL();
	}
	void freeTreeAVL(void){
		freeNode(&this->_root);
		this->_size = 0;
	}

	void freeNode(node_type **node){
		if(!(*node))
			return;
		if((*node)->_right)
			freeNode(&((*node)->_right));
		if((*node)->_left)
			freeNode(&((*node)->_left));
		_alloc_pair.destroy((*node)->_pair);
		_alloc_pair.deallocate((*node)->_pair, 1);
		(*node)->_pair = NULL;
		_alloc.destroy((*node));
		_alloc.deallocate((*node), 1);
		*node = NULL;
	}
	int updateHeight(node_type *node){
		int heightRight;
		int heightLeft;

		heightRight = node->_right ? node->_right->_height : 0;
		heightLeft = node->_left ? node->_left->_height : 0;
		if(heightRight > heightLeft)
			return heightRight + 1;
		return heightLeft + 1; 
	}
	bool isItNecessaryToRebalance(node_type *node){
		int heightRight;
		int heightLeft;

		heightRight = node->_right ? node->_right->_height : 0;
		heightLeft = node->_left ? node->_left->_height : 0;
		if(abs(heightLeft - heightRight) >= 2)
			return true;
		return false;
	}
	node_type *doubleRightRotation(node_type **oldParentNode, node_type *grandParent){
		node_type *aux = (*oldParentNode)->_right;
		(*oldParentNode)->_right = simpleLeftRotation(&((*oldParentNode)->_right), aux);
		return simpleRightRotation(&(*oldParentNode), grandParent);
	}
	node_type *doubleLeftRotation(node_type **oldParentNode, node_type *grandParent){
		node_type *aux = (*oldParentNode)->_left;
		(*oldParentNode)->_left = simpleRightRotation(&((*oldParentNode)->_left), aux);
		return simpleLeftRotation(&(*oldParentNode), grandParent);
	}
	node_type *simpleRightRotation(node_type **oldParentNode, node_type *grandParent){
		node_type *newParentNode = (*oldParentNode)->_right;
		node_type *aux = newParentNode->_left;
		newParentNode->_left = (*oldParentNode);
		(*oldParentNode)->_right = aux;
		(*oldParentNode)->_height = updateHeight((*oldParentNode));
		newParentNode->_parent = grandParent;
		(*oldParentNode)->_parent = newParentNode;
		if (aux)
			aux->_parent = *oldParentNode;
		return newParentNode;
	}
	node_type *simpleLeftRotation(node_type **oldParentNode, node_type *grandParent){
		node_type *newParentNode = (*oldParentNode)->_left;
		node_type *aux = newParentNode->_right;
		newParentNode->_right = (*oldParentNode);
		(*oldParentNode)->_left = aux;
		(*oldParentNode)->_height = updateHeight((*oldParentNode));
		newParentNode->_parent = grandParent;
		(*oldParentNode)->_parent = newParentNode;
		if (aux)
			aux->_parent = *oldParentNode;
		return newParentNode;
	}
	node_type *rebalanceTreeAVL(node_type **oldParentNode, node_type *grandParent, pair_type &data){
		int heightRight;
		int heightLeft;
		int aux;

		heightRight = (*oldParentNode)->_right ? (*oldParentNode)->_right->_height : 0;
		heightLeft = (*oldParentNode)->_left ? (*oldParentNode)->_left->_height : 0;
		aux = heightLeft - heightRight;
		if(aux > 0){
			if (_less(data.first, (*oldParentNode)->_pair->first) && _less((*oldParentNode)->_left->_pair->first, data.first))
				return doubleLeftRotation(&(*oldParentNode), grandParent);
			else
				return simpleLeftRotation(&(*oldParentNode), grandParent);
		} 
		else if(aux < 0){
			if (_less((*oldParentNode)->_pair->first, data.first) && _less(data.first, (*oldParentNode)->_right->_pair->first))
				return doubleRightRotation(&(*oldParentNode), grandParent);
			else
				return simpleRightRotation(&(*oldParentNode), grandParent);
		}
		return (*oldParentNode);
	}
	node_type *findApproximate(pair_type data){
		if(!_root)
			return NULL;
		return findApproximate(this->_root, data);
	}
	node_type *findApproximate(node_type *node, pair_type &data){
		if(areKeysEqual(data.first, node->_pair->first))
			return node;
		else if(_less(data.first, node->_pair->first)){
			if(node->_left)
				return findApproximate(node->_left, data);
			return node;
		}
		if(node->_right)
			return findApproximate(node->_right, data);
		return node;
	}
	node_type *find(pair_type data){
		return find(this->_root, data);
	}
	node_type *find( node_type *node, pair_type &data){
		if(!node)
			return NULL;
		else if (areKeysEqual(data.first, node->_pair->first))
			return node;
		else if (_less(data.first, node->_pair->first))
			return find(node->_left, data);
		return find(node->_right, data);
	}
	void copyTreeFromAnotherAVL(node_type *other){
		if(!other)
			return;
		this->insertData(*(other->_pair));
		if(other->_left)
			copyTreeFromAnotherAVL(other->_left);
		if(other->_right)
			copyTreeFromAnotherAVL(other->_right);
	}
	ft::pair<node_type *, bool> insertData(pair_type data){
		return insertNode(NULL, &this->_root, data);
	}
	node_type *beginIterator(void){
		return min(&this->_root);
	}
	node_type *endIterator(void){
		return max(&this->_root);
	}
	size_t getSize(void){
		return this->_size;
	}
	ft::pair<node_type *, bool > insertNode(node_type *parentNode, node_type **node, pair_type &data){
		ft::pair<node_type *, bool> ret;
		if (!(*node)){
			*node = _alloc.allocate(1);
			(*node)->_pair = _alloc_pair.allocate(1);
			_alloc_pair.construct((*node)->_pair, data);
			(*node)->_parent = parentNode;
			(*node)->_height = 1;
			(*node)->_right = NULL;
			(*node)->_left = NULL;
			ret = ft::make_pair(*node, true);
			this->_size += 1;
		}
		else if (areKeysEqual(data.first, (*node)->_pair->first))
			ret = ft::make_pair(*node, false);
		else if (_less((*node)->_pair->first, data.first)){
			ret = insertNode(*node, &((*node)->_right), data);
			if(isItNecessaryToRebalance(*node))
				(*node) = rebalanceTreeAVL(&(*node), parentNode, data);
			(*node)->_height = updateHeight(*node);
		}
		else if (_less(data.first, (*node)->_pair->first)){
			ret = insertNode(*node, &((*node)->_left), data);
			if(isItNecessaryToRebalance(*node))
				(*node) = rebalanceTreeAVL(&(*node), parentNode, data);
			(*node)->_height = updateHeight(*node);
		}
		return ret;
	}
	node_type *max(node_type **node){
		if (!(*node) || !((*node)->_right))
			return (*node);
		return max(&((*node)->_right));
	}
	node_type *min(node_type **node){
		if (!(*node) || !((*node)->_left))
			return (*node);
		return min(&((*node)->_left));
	}

	node_type *max(void){
		return max(&this->_root);
	}
	node_type *min(void){
		return min(&this->_root);
	}
	size_t deleteData(pair_type data){
		size_t beforeSize = this->_size;
		deleteNode(NULL, &this->_root, data, true);
		return this->_size - beforeSize;
	}
	void deleteNode(node_type *parentNode, node_type **node, pair_type &data, bool deallocatePair){
		if (!(*node))
			return;
		else if (areKeysEqual(data.first, (*node)->_pair->first)) {
			if((*node)->_height == 1){
				if(deallocatePair){
					_alloc_pair.destroy((*node)->_pair);
					_alloc_pair.deallocate((*node)->_pair, 1);
					(*node)->_pair = NULL;
				}
				_alloc.destroy((*node));
				_alloc.deallocate((*node), 1);
				*node = NULL;
				this->_size -= 1;
				return;
			}
			pair_type *newData = (*node)->_left ? max(&((*node)->_left))->_pair \
								: (*node)->_right->_pair;
			deleteNode(parentNode, &(*node), *newData, false);
			if(deallocatePair){
				_alloc_pair.destroy((*node)->_pair);
				_alloc_pair.deallocate((*node)->_pair, 1);
				(*node)->_pair = NULL;
			}
			(*node)->_pair = newData;
		}
		else if (_less((*node)->_pair->first, data.first)){
			deleteNode(*node, &((*node)->_right), data, deallocatePair);
			if(isItNecessaryToRebalance(*node))
				(*node) = rebalanceTreeAVL(&(*node), parentNode, data);
			(*node)->_height = updateHeight(*node);
		}
		else if (_less(data.first, (*node)->_pair->first)){
			deleteNode(*node, &((*node)->_left), data, deallocatePair);
			if(isItNecessaryToRebalance(*node))
				(*node) = rebalanceTreeAVL(&(*node), parentNode, data);
			(*node)->_height = updateHeight(*node);
		}
	}

	void printNode(node_type *node){
		if (!node)
			return;
		if(node->_parent)
			std::cout << "Parent: " << node->_parent->_pair->first << "\n";
		else
			std::cout << "Parent: null\n";
		std::cout << "Key: " << node->_pair->first << "\n";
		std::cout << "Value: " << node->_pair->second << "\n";
		if(node->_right)
			std::cout << "R: " << node->_right->_pair->first << "\n";
		else
			std::cout << "R: null\n";
		if(node->_left)
			std::cout << "L: " << node->_left->_pair->first << "\n";
		else
			std::cout << "L: null\n";
		std::cout << "H: " << node->_height << "\n\n";
	}
	void printNodes(node_type *node){
		if (!node)
			return;
		printNode(node);
		printNodes(node->_right);
		printNodes(node->_left);
	}
};

#endif

		