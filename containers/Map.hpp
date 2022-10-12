/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/07 23:32:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include<functional>
# include<utility>
# include "./aux/bidirectional_iterator.hpp"
# include "./aux/reverse_iterator.hpp"
# include "./aux/AVL.hpp"
# include "aux/lexicographical_compare.hpp"
# include "aux/equal.hpp"

namespace ft{
	template <class Key, class T, class Compare = std::less< Key >, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const key_type, mapped_type>					value_type;
			typedef std::size_t												size_type;
			typedef std::ptrdiff_t											difference_type;
			typedef Compare													key_compare;
			typedef Allocator												allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::bidirectional_iterator<value_type, allocator_type, key_compare>	iterator;
			typedef typename ft::bidirectional_iterator<value_type, allocator_type, key_compare>	const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		private:
			typedef AVL<value_type, allocator_type, key_compare> avl_type;
			typedef Node<value_type> node;
			allocator_type alloc;
			key_compare _less;
			std::allocator<avl_type> _alloc_avl;
			avl_type* _avl;

		public:
			/*[CONSTRUCTORS]*/
			explicit map(const key_compare &comp = key_compare(), const allocator_type &allocator = Allocator()): alloc(allocator), _less(comp) {
				avl_type avl_base;
				this->_avl = _alloc_avl.allocate(1);
				_alloc_avl.construct(this->_avl, avl_base);
			}
			template<class InputIt>
			map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &allocator = Allocator()): alloc(allocator), _less(comp){
				avl_type avl_base;
				this->_avl = _alloc_avl.allocate(1);
				_alloc_avl.construct(this->_avl, avl_base);
				this->insert(first, last);
			}
			map(const map &other){
				avl_type avl_base;
				this->_avl = _alloc_avl.allocate(1);
				_alloc_avl.construct(this->_avl, avl_base);
				*this = other;
			}

			/*[DESTRUCTORS]*/
			~map(){
				_alloc_avl.destroy(this->_avl);
				_alloc_avl.deallocate(this->_avl, 1);
			}

			/*[OPERATOR=]*/
			map &operator=(const map &other){
				this->clear();
				this->_avl->copyTreeFromAnotherAVL(other._avl->_root);
				return (*this);
			}

			/*[ITERATORS]*/
			iterator begin(){
				return iterator(_avl->beginIterator(), _avl);
			}
			const_iterator begin() const{
				return const_iterator(_avl->beginIterator(), _avl);
			}
			iterator end(){
				return iterator(NULL, _avl);
			}
			const_iterator end() const{
				return const_iterator(NULL, _avl);
			}
			reverse_iterator rbegin() {
				return reverse_iterator(iterator(_avl->max(), _avl, false));
			}
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(iterator(_avl->max(), _avl, false));
			}
			reverse_iterator rend() {
				return reverse_iterator(iterator(NULL, _avl, false));
			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(iterator(NULL, _avl, false));
			}

			/*[CAPACITY]*/
			bool empty() const {
				if(size() > 0)
					return false;
				return true;
			}
			size_type size() const{
				return _avl->getSize();
			}
			size_type max_size() const{
				return _avl->_alloc.max_size();
			}


			/*[ELEMENT ACCESS]*/
			mapped_type &operator[](const key_type &key){
				value_type pair = ft::make_pair(key, mapped_type());
				node *ptr = _avl->find(pair);
				
				if(ptr)
					return ptr->_pair->second;
				return _avl->insertData(pair).first->_pair->second;
			}
			mapped_type &at(const key_type &k){
				node *ptr = _avl->find(ft::make_pair(k, mapped_type()));
				if(!ptr)
					throw std::out_of_range("Out of range");
				return ptr->_pair->second;
			}
			const mapped_type &at(const key_type &k) const{
				node *ptr = _avl->find(ft::make_pair(k, mapped_type()));
				if(!ptr)
					throw std::out_of_range("Out of range");
				return ptr->_pair->second;
			}

			/*[MODIFIERS]*/
			ft::pair<iterator, bool> insert(const value_type &value){
				ft::pair<node *, bool> pair;
				pair = _avl->insertData(value);
				return ft::make_pair(iterator(pair.first, this->_avl), pair.second);
			}
			iterator insert(iterator hint, const value_type &value){
				(void) hint;
				ft::pair<node *, bool> pair;
				pair = _avl->insertData(value);
				return iterator(pair.first, this->_avl);
			}
			template<class InputIt>
			void insert(InputIt firstIt, InputIt lastIt){
				while(firstIt != lastIt){
					_avl->insertData(*firstIt);
					++firstIt;
				}
			}
			void erase(iterator position){
				_avl->deleteData(*position);
			}
			size_type erase(const key_type &key){
				return _avl->deleteData(ft::make_pair(key, mapped_type()));
			}
			void erase(iterator first, iterator last){
				int count = 0;
				node *ptr;
				iterator aux = first;
				value_type base = ft::make_pair((*first).first, mapped_type());
				while(aux != last){
					++aux;
					++count;
				}
				while(--count >= 0){
					ptr = _avl->lowerBound(base);
					_avl->deleteData(*(ptr->_pair));
				}
			}
			void swap(map &other){
				allocator_type xalloc;
				std::allocator<avl_type> x_alloc_avl;
				avl_type* x_avl;

				xalloc= other.alloc;
				x_alloc_avl = other._alloc_avl;
				x_avl = other._avl;
				other.alloc = this->alloc;
				other._alloc_avl = this->_alloc_avl;
				other._avl = this->_avl;
				this->alloc = xalloc;
				this->_alloc_avl = x_alloc_avl;
				this->_avl = x_avl;
			}
			void clear(){
				_avl->freeTreeAVL();
			}

			/*[OBSERVERS]*/
			class value_compare: public std::binary_function<value_type, value_type, bool> {
				friend class map;
				protected:
					Compare comp;
					value_compare( Compare c ): comp(c) {}
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool	operator()( const value_type &lhs, const value_type &rhs ) const { return (comp(lhs.first, rhs.first)); }
			};
			key_compare		key_comp() const{return _less;}
			value_compare	value_comp(void) const { return (value_compare(_less)); }
			
			/*[OPERATIONS]*/
			iterator find(const Key &key){
				node *pair;

				pair = _avl->find(ft::make_pair(key, mapped_type()));
				if(pair)
					return iterator(pair, _avl);
				return iterator(NULL, _avl);
			}
			const_iterator find(const Key &key) const{
				node *pair;

				pair = _avl->find(ft::make_pair(key, mapped_type()));
				if(pair)
					return const_iterator(pair, _avl);
				return const_iterator(NULL, _avl);
			}
			size_type count(const Key &key) const{
				if(_avl->find(ft::make_pair(key, mapped_type())))
					return 1;
				return 0;
			}
			iterator lower_bound(const Key &key){
				value_type pair = ft::make_pair(key, mapped_type());
				return iterator(_avl->lowerBound(pair), _avl);
			}
			const_iterator lower_bound(const Key &key) const{
				value_type pair = ft::make_pair(key, mapped_type());
				return const_iterator(_avl->lowerBound(pair), _avl);
			}
			iterator upper_bound(const Key &key){
				value_type pair = ft::make_pair(key, mapped_type());
				return iterator(_avl->upperBound(pair), _avl);
			}
			const_iterator upper_bound(const Key &key) const{
				value_type pair = ft::make_pair(key, mapped_type());
				return const_iterator(_avl->upperBound(pair), _avl);
			}
			ft::pair<iterator, iterator> equal_range(const Key &key){
				iterator first = this->lower_bound(key);
				iterator second = this->upper_bound(key);
				return ft::make_pair(first, second);
			}
			ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const{
				const_iterator first = this->lower_bound(key);
				const_iterator second = this->upper_bound(key);
				return ft::make_pair(first, second);
			}

			/*[ALLOCATOR]*/
			allocator_type get_allocator() const{
				return this->alloc;
			}
		
	};
	template< class Key, class T, class Compare, class Alloc >
	bool	operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		if(lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin())); 
	}
	template< class Key, class T, class Compare, class Alloc >
	bool	operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return ((lhs > rhs) ? false : true); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return ((lhs < rhs) ? false : true); }
	template< class Key, class T, class Compare, class Alloc >
	void	swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs ) { lhs.swap(rhs); }
}
#endif