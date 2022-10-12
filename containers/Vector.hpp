/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/11 10:29:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <memory>
# include <typeinfo>
# include "aux/enable_if.hpp"
# include "aux/is_integral.hpp"
# include "aux/reverse_iterator.hpp"
# include "aux/lexicographical_compare.hpp"
# include "aux/equal.hpp"
# include "aux/random_access_iterator.hpp"

namespace ft{
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			unsigned int _capacity;
			unsigned int _size;
			Allocator _alloc;
			pointer _data;
			bool _isObject;

		public:
		//constructors and destructor
			explicit vector (const allocator_type& alloc = allocator_type()):
			_capacity(0),
			_size(0),
			_alloc(alloc),
			_data(NULL),
			_isObject(false) {
				value_type val =  value_type(); 
				this->_isObject = _checkIsObject(val);
			};

			explicit vector (size_type n, const value_type& val = value_type(), 
							const allocator_type& alloc = allocator_type()):
			_capacity(n),
			_size(n),
			_alloc(alloc),
			_data(this->_alloc.allocate(n)),
			_isObject(false) {
				this->_isObject = _checkIsObject(val);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_data + i, val);
			}

			template <class InputIterator>
        	vector (InputIterator first, InputIterator last,
                	const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0):
			_capacity(last - first),
			_size(this->_capacity),
			_alloc(alloc),
			_data(this->_alloc.allocate(this->_capacity)), 
			_isObject(false) {
				pointer base = &(*first);
				value_type val =  value_type();
				this->_isObject = _checkIsObject(val);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_data + i, *(base + i));
			}

			vector (const vector& x):
			_capacity(0),
			_size(0),
			_alloc(x._alloc),
			_data(NULL), 
			_isObject(false) {
				*this = x;
			}

			vector&	operator=(const vector& other)
			{
				this->clear();
				if (this->_capacity < other._size)
					this->_data = _newData(other._size);
				for (size_type i = 0; i < other._size; i++)
					this->_alloc.construct(&this->_data[i], other._data[i]);
				this->_size = other._size;
				return (*this);
			}

			~vector(){
				for(unsigned int index = 0; index < this->_capacity; ++index)
					_alloc.destroy(this->_data + index);
				if(this->_data)
					_alloc.deallocate(this->_data, this->_capacity);
				this->_data = NULL;
			}

		//iterators
			iterator begin(void){
				return(iterator(this->_data)); 
			}
			const_iterator begin(void)const{
				return(const_iterator(this->_data)); 
			}
			iterator end(void){
				return(iterator(this->_data + this->_size)); 
			}
			const_iterator end(void)const{
				return(const_iterator(this->_data + this->_size)); 
			}
			reverse_iterator rbegin(void){
				return(reverse_iterator(this->end() - 1)); 
			}
			const_reverse_iterator rbegin(void)const{
				return(const_reverse_iterator(this->end() - 1)); 
			}
			reverse_iterator rend(void){
				return(reverse_iterator(this->begin() - 1)); 
			}
			const_reverse_iterator rend(void)const{
				return(const_reverse_iterator(this->begin() - 1)); 
			}

		//capacity
			size_type size()const{
				return this->_size;
			}
			size_type max_size() const{
				return this->_alloc.max_size();
			}
			void resize (size_type n, value_type val = value_type()){
				if (n <  this->size())
					this->_size = n;
				else if (n > this->_capacity)
					this->reserve(n < this->size() * 2 ? this->size() * 2 : n);
				while (n > this->_size)
					this->push_back(val);
			}
			size_type capacity(void)const{
				return this->_capacity;
			}
			bool empty(void)const{
				return !this->_size ? true : false;
			}
			void reserve( size_type new_cap ){
				if (new_cap <= this->_capacity)
					return;
				if (new_cap > this->max_size())
					throw std::length_error("length_error");
				unsigned int oldCapacity = this->_capacity;
				pointer destiny = _newData(new_cap);
				_copyData(this->_data, destiny, this->_size);
				if(this->_isObject){
					for(unsigned int x = 0; x < oldCapacity; ++x)
						_alloc.destroy(this->_data + x);
				}
				_alloc.deallocate(this->_data, oldCapacity) ;
				this->_data = destiny;
			}

		//element access
			reference operator[](size_t pos){
				return(this->_data[pos]);
			}
			const_reference operator[](size_t pos)const{
				return(this->_data[pos]);
			}
			reference at(size_type n){
				if (n >= this->_size)
					throw vector::OutOfRange();
				return (this->_data[n]);
			}
			const_reference at(size_type n) const{
				if (n >= this->_size)
					throw vector::OutOfRange();
				return (this->_data[n]);
			};
			reference front(){
				return (this->_data[0]);
			}
			const_reference front() const{
				return (this->_data[0]);
			}
			reference back(){
				return (this->_data[this->_size - 1]);
			}
			const_reference back() const{
				return (this->_data[this->_size - 1]);
			}
			pointer data() {return this->_data;}
			const_pointer data() const {return this->_data;}
			
		//modifiers
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false){
				size_type count = last - first;
				if (count > this->_capacity){
					unsigned int oldCapacity = this->_capacity;
					pointer destiny = _newData(count);
					for(unsigned int x = 0; x < oldCapacity; ++x)
						_alloc.destroy(this->_data + x);
					_alloc.deallocate(this->_data, oldCapacity) ;
					this->_data = destiny;
				}
				else{
					for(unsigned int x = 0; x < this->_capacity; ++x)
						_alloc.destroy(this->_data + x);
				}
				this->_size = count;
				while(count)
					_alloc.construct(this->_data + (--count), *(--last));
			}
			void assign( size_type count, const value_type& value ){
				if (count > this->_capacity){
					unsigned int oldCapacity = this->_capacity;
					pointer destiny = _newData(count);
					if (this->_isObject){
						for(unsigned int x = 0; x < oldCapacity; ++x)
							_alloc.destroy(this->_data + x);
					}
					_alloc.deallocate(this->_data, oldCapacity) ;
					this->_data = destiny;
				}
				else{
					if (this->_isObject){
						for(unsigned int x = 0; x < this->_capacity; ++x)
							_alloc.destroy(this->_data + x);
					}
				}
				this->_size = count;
				while(count)
					_alloc.construct(this->_data + (--count), value);
			}
			void push_back(const value_type& val){
				if(this->_size == this->_capacity){
					unsigned int oldCapacity = this->_capacity;
					pointer destiny = _newData();
					_copyData(this->_data, destiny, this->_size);
					for(unsigned int x = 0; x < oldCapacity; ++x)
						_alloc.destroy(this->_data + x);
					_alloc.deallocate(this->_data, oldCapacity) ;
					this->_data = destiny;
				}
				this->_data[this->_size] = val;
				this->_size += 1;
			};
			void pop_back(){
				this->_size -= 1;
			}
			iterator insert (iterator position, const value_type& val){
				pointer insertePosition = &(*position);
				pointer baseNewIterator = NULL;

				if(this->_size >= this->_capacity){
					unsigned int indexData = 0;
					unsigned int indexDestiny = 0;
					unsigned int oldCapacity = this->_capacity;
					pointer destiny = _newData();
					while(indexData <= this->_size){
						if(!baseNewIterator && insertePosition == this->_data + indexData){
							destiny[indexDestiny] = val;
							baseNewIterator = destiny + indexDestiny;	
							if(!this->_data) break;
						}
						else {
							destiny[indexDestiny] = this->_data[indexData];
							++indexData;
						}
						++indexDestiny;
					}
					if(this->_isObject){
						for(unsigned int x = 0; x < oldCapacity; ++x)
							_alloc.destroy(this->_data + x);
					}
					_alloc.deallocate(this->_data, oldCapacity);
					this->_data = destiny;
				}else{
					for(int count = this->_size; count >= 0; --count){
						if(insertePosition == this->_data + count){
							this->_data[count] = val;
							baseNewIterator = this->_data + count;
							break;
						}
						else 
							this->_data[count] = this->_data[count - 1];
					}
				}
				this->_size += 1;
				return iterator(baseNewIterator);
			}
			void insert (iterator position, size_type n, const value_type& val){
				pointer insertePosition = &(*position);

				if(this->_size + n > this->_capacity){
					unsigned int indexData = 0;
					unsigned int indexDestiny = 0;
					unsigned int oldCapacity = this->_capacity;
					pointer destiny = _newData(this->_size * 2 >= this->_size + n ? this->_size * 2 : this->_size + n);
					while(indexData <= this->_size){
						if(insertePosition == this->_data + indexData){
							for(unsigned int x = 0; x < n; ++x)
								destiny[indexDestiny++] = val;
							if(!this->_data) break;
						}
						destiny[indexDestiny] = this->_data[indexData];
						++indexData;
						++indexDestiny;
					}
					if(this->_isObject){
						for(unsigned int x = 0; x < oldCapacity; ++x)
							_alloc.destroy(this->_data + x);
					}
					_alloc.deallocate(this->_data, oldCapacity);
					this->_data = destiny;
				}else{
					for(int count = this->_size + n; count >= 0; --count){
						if(insertePosition == this->_data + count - n + 1){
							for(unsigned int x = 0; x < n; ++x)
								this->_data[count--] = val;
							break;
						}
						else 
							this->_data[count] = this->_data[count - n];
					}
				}
				this->_size += n;
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0){
				pointer insertePosition = &(*position);
				difference_type n = last - first;

				if(this->_size + n > this->_capacity){
					unsigned int indexData = 0;
					unsigned int indexDestiny = 0;
					unsigned int oldCapacity = this->_capacity;
					pointer destiny = _newData(this->_size * 2 >= this->_size + n ? this->_size * 2 : this->_size + n);
					while(indexData <= this->_size){
						if(insertePosition == this->_data + indexData){
							for(unsigned int x = 0; x < n; ++x){
								destiny[indexDestiny++] = *first;
								++first;
							}
							if(!this->_data) break;
						}
						destiny[indexDestiny] = this->_data[indexData];
						++indexData;
						++indexDestiny;
					}
					if(this->_isObject){
						for(unsigned int x = 0; x < oldCapacity; ++x)
							_alloc.destroy(this->_data + x);
					}
					_alloc.deallocate(this->_data, oldCapacity);
					this->_data = destiny;
				}else{
					for(int count = this->_size + n; count >= 0; --count){
						if(insertePosition == this->_data + count - n + 1){
							for(unsigned int x = 0; x < n; ++x)
								this->_data[count--] = *(--last);
							break;
						}
						else 
							this->_data[count] = this->_data[count - n];
					}
				}
				this->_size += n;
			}
			iterator erase(iterator position){
				iterator itStart = this->begin();
				iterator itEnd = this->end();
				if (this->_size == 0 || position >= itEnd || position < itStart)
					throw std::out_of_range("ft::vector::erase");
				for(difference_type index = position - itStart; index < this->_size - 1; ++index)
					this->_data[index] = this->_data[index + 1];
				if(this->_isObject)
					_alloc.destroy(this->_data + this->_size - 1);
				this->_size -= 1;
				return position;
			}
			iterator erase (iterator first, iterator last){
				iterator itStart = this->begin();
				iterator itEnd = this->end();
				int range = last - first;
				if (this->_size == 0 || range < 0 || first < itStart || last > itEnd)
					throw std::out_of_range("ft::vector::erase");
				for(int indexStart = first - itStart;\
				(this->_data + indexStart + range) != this->_data + this->_size;\
				++indexStart)
				{
					_alloc.destroy(this->_data + indexStart);
					_alloc.construct(this->_data + indexStart, this->_data[indexStart + range]);
				}
				this->_size -= last - first;
				return first;
			}
			void swap(vector &x){
				pointer tmpData = x._data;
				unsigned int tmpCapacity = x._capacity;
				unsigned int tmpSize = x._size;

				x._data = this->_data;
				x._size = this->_size;
				x._capacity = this->_capacity;

				this->_data = tmpData;
				this->_size = tmpSize;
				this->_capacity = tmpCapacity;
			}
			void clear(){
				if(!this->_capacity)
					return;
				pointer destiny = _newData(this->_capacity);
				_copyData(this->_data, destiny, this->_size);
				if(this->_isObject){
					for(unsigned int x = 0; x < this->_capacity; ++x)
						_alloc.destroy(this->_data + x);
				}
				_alloc.deallocate(this->_data, this->_capacity);
				this->_data = destiny;
				this->_size = 0;
			}
			
		//Allocator:
			allocator_type get_allocator() const{
				return this->alloc;
			}
			
		private:
			class OutOfRange : public std::exception
			{
				public:
					OutOfRange(){}
					virtual const char* what() const throw()
					{
						return ("Out of Range error: vector::_M_range_check");
					}
			};
			pointer _newData(unsigned int insertedCapacity = 0){
				unsigned int newCapacity = 0;
				if (insertedCapacity)
					newCapacity = insertedCapacity;
				else
					newCapacity = !this->_capacity ? 1 : this->_capacity * 2;
				pointer ptr = _alloc.allocate(newCapacity + 1);
				if (!ptr)
					throw std::bad_alloc();
				if(this->_isObject){
					for(unsigned int x = 0; x < newCapacity; ++x)
						_alloc.construct(ptr + x, value_type());
				}
				this->_capacity = newCapacity; 
				return ptr;
			}
			void _copyData(pointer src, pointer dst, unsigned int quantityCopy){
				int count = quantityCopy;
				while(--count >= 0)
					dst[count] = src[count];
			}
			bool _checkIsObject(T element){
				std::string type;
				try{ type = typeid(element).name(); }
				catch(...){ return false; }
				std::string typeName = _removeRepresentationPointersFromTypeName(type);

				if(typeName == typeid(char).name())
					return false;
				if(typeName == typeid(wchar_t).name())
					return false;
				if(typeName == typeid(int).name())
					return false;
				if(typeName == typeid(double).name())
					return false;
				if(typeName == typeid(float).name())
					return false;
				if(typeName == typeid(bool).name())
					return false;
				if(typeName == typeid(long int).name())
					return false;
				if(typeName == typeid(short int).name())
					return false;
				if(typeName == typeid(unsigned int).name())
					return false;
				if(typeName == typeid(unsigned short int).name())
					return false;
				if(typeName == typeid(signed short int).name())
					return false;
				if(typeName == typeid(signed long int).name())
					return false;
				if(typeName == typeid(unsigned long int).name())
					return false;
				if(typeName == typeid(unsigned char).name())
					return false;
				return true;
			}
			std::string _removeRepresentationPointersFromTypeName(std::string &type){
				const char *typeNameChar = type.c_str();
				const char representatioPointer = 'P';
				unsigned int index = 0;

				while(typeNameChar[index] == representatioPointer)
					++index;
				std::string typeNameWithoutP(&(typeNameChar[index]));
				return typeNameWithoutP;
			}
	};
	template< class T, class Alloc >
	void	swap( vector<T, Alloc>& lhs, vector<T, Alloc>& rhs ) { lhs.swap(rhs); }
	template< class T, class Alloc >
	bool	operator== ( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		if(lhs.size() != rhs.size())
			return false; 
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin())); 
	}
	template< class T, class Alloc >
	bool	operator!= ( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return !(lhs == rhs);}
	template< class T, class Alloc >
	bool	operator<  ( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template< class T, class Alloc >
	bool	operator<= ( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return ((lhs > rhs) ? false : true); }
	template< class T, class Alloc >
	bool	operator>  ( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); }
	template< class T, class Alloc >
	bool	operator>= ( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return ((lhs < rhs) ? false : true); }
}
#endif