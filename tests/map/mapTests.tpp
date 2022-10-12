/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:14:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/mapTests.hpp"
#include<typeinfo>

class person {
	public:
		std::string _name;
		size_t _years;
		person(): _name("default"), _years(1980){};
		person(std::string name, size_t years): _name(name), _years(years){};
		person(const person &p): _name(p._name), _years(p._years){};
		~person(){}
		void setName(std::string name){this->_name = name;}
		std::string getName(void){return this->_name;}
		void setYears(size_t years){this->_years = years;}
		size_t getYears(void){return this->_years;}
};
bool operator==( const person & lhs, const person& rhs ) { return (lhs._years == rhs._years); }
bool operator!=( const person& lhs, const person& rhs ) { return (lhs._years != rhs._years); }	
bool operator<( const person& lhs, const person& rhs ) { return (lhs._years < rhs._years); }	
bool operator<=( const person& lhs, const person& rhs ) { return (lhs._years <= rhs._years); }	
bool operator>( const person& lhs, const person& rhs ) { return (lhs._years > rhs._years); }	
bool operator>=( const person& lhs, const person& rhs ) { return (lhs._years >= rhs._years); }

template<class Key, class Value>
void insertGeneric(std::map<int, person> &map, Key key, Value value){
		map.insert(std::make_pair(key, value));	
}
template<class Key, class Value>
void insertGeneric(ft::map<int, person> &map, Key key, Value value){
		map.insert(ft::make_pair(key, value));	
}

template<class mapPerson>
void mapTests(mapPerson &map){
	map.size();
	std::cout << "CONSTRUCTOR VOID: \n";
	mapPerson mapVoid;
	std::cout << "size: " << mapVoid.size() << "\n\n";


	mapPerson temp1;
	for(unsigned int x = 0; x < 100; ++x){
		insertGeneric(temp1, x, person("Bill", x));
	}
	std::cout << "CONSTRUCTOR RANGE: \n";
	mapPerson mapRange(temp1.begin(), temp1.end());
	std::cout << "size base: " << temp1.size() << "\n";
	std::cout << "size result: " << mapRange.size() << "\n\n";

	std::cout << "CONSTRUCTOR COPY: \n";
	mapPerson mapCopy(mapRange);
	std::cout << "size base: " << mapRange.size() << "\n";
	std::cout << "size result: " << mapCopy.size() << "\n\n";

	std::cout << "INSERT: \n";
	std::cout << "size before: " << mapVoid.size() << "\n";
	for(size_t x = 0; x < 125; ++x)
		insertGeneric(mapVoid, x, person("Tarcisio", x));
	std::cout << "size after: " << mapVoid.size() << "\n\n";

	std::cout << "MAX SIZE: ";
	std::cout <<(mapVoid.max_size() ? "OK" : "KO")  << "\n\n";
	
	std::cout << "EMPTY: \n";
	mapPerson mapTeste;
	std::cout << (mapTeste.empty() ? "true\n" : "false\n");
	std::cout << (mapVoid.empty() ? "true\n" : "false\n\n");
	

	std::cout << "\nAT: \n";
	try{
		for(size_t x = 0; x < mapVoid.size(); ++x){
			std::cout << "name: " << mapVoid.at(x).getName() << "\n";
			std::cout << "years: " << mapVoid.at(x).getYears() << "\n\n";
		}
	}catch(...){
		std::cout << "ERROR IN METHOD AT\n\n";
	}

	std::cout << "\nERASE: \n";
	unsigned int amountErased = 12;
	std::cout << "size before: " << mapVoid.size() << "\n";
	std::cout << "amount erased: " << amountErased << "\n";
	typename mapPerson::iterator it = mapVoid.end();
	for(unsigned int x = mapVoid.size() / 2; x; --x){
		--it;
	}
	typename mapPerson::iterator end = it;
	for(unsigned int x = amountErased; x; --x){
		--it;
	}
	typename mapPerson::iterator start = it;
	mapVoid.erase(start, end);
	std::cout << "size after: " << mapVoid.size() << "\n\n";

	mapPerson empty;
	std::cout << "SWAP: \n"; 
	std::cout << "[first exchange]\n";
	swap(mapVoid, empty);
	std::cout << "size before: " << mapVoid.size() << "\n";
	std::cout << "[undoing the exchange]\n";
	swap(mapVoid, empty);
	std::cout << "size after: " << mapVoid.size() << "\n\n";


	std::cout << "CLEAR: \n";
	std::cout << "[before]\n";
	std::cout << "size: " << mapCopy.size() << "\n";
	mapCopy.clear();
	std::cout << "[after]\n";
	std::cout << "size: " << mapCopy.size() << "\n";

	std::cout << "\nBEGIN: \n";
	typename mapPerson::iterator it1;
	it1 = mapVoid.begin();
	while(it1 != mapVoid.end()){
		std::cout << "num: " << it1->first; 
		std::cout << "name: " << it1->second.getName() << "\n";
		std::cout << "years: " << it1->second.getYears() << "\n";
		++it1;
	}

	std::cout << "\nEND: \n";
	it1 = mapVoid.end();
	while(it1 != mapVoid.begin()){
		--it1;
		std::cout << "num: " << it1->first; 
		std::cout << "name: " << it1->second.getName() << "\n";
		std::cout << "years: " << it1->second.getYears() << "\n";
	}
	std::cout << "num: " << it1->first; 
	std::cout << "name: " << it1->second.getName() << "\n";
	std::cout << "years: " << it1->second.getYears() << "\n";

	std::cout << "\nRBEGIN: \n";
	typename mapPerson::reverse_iterator rit;
	rit = mapVoid.rbegin();
	while(rit != mapVoid.rend()){
		std::cout << "num: " << rit->first; 
		std::cout << "name: " << rit->second.getName() << "\n";
		std::cout << "years: " << rit->second.getYears() << "\n";
		++rit;
	}

	std::cout << "\nREND: \n";
	rit = mapVoid.rend();
	while(--rit != mapVoid.rbegin()){
		std::cout << "num: " << rit->first; 
		std::cout << "name: " << rit->second.getName() << "\n";
		std::cout << "years: " << rit->second.getYears() << "\n";
	}
	std::cout << "num: " << rit->first; 
	std::cout << "name: " << rit->second.getName() << "\n";
	std::cout << "years: " << rit->second.getYears() << "\n";

	std::cout << "RELATIONAL OPERATOR: \n";
	std::cout << "[vectorFull > vectorEmpty]: " << (mapVoid > empty ? "true\n" : "false\n");
	std::cout << "[vectorFull >= vectorEmpty]: " << (mapVoid >= empty ? "true\n" : "false\n");
	std::cout << "[vectorFull < vectorEmpty]: " << (mapVoid < empty ? "true\n" : "false\n");
	std::cout << "[vectorFull <= vectorEmpty]: " << (mapVoid <= empty ? "true\n" : "false\n");
	std::cout << "[vectorFull == vectorEmpty]: " << (mapVoid == empty ? "true\n" : "false\n");
	std::cout << "[vectorFull != vectorEmpty]: " << (mapVoid != empty ? "true\n" : "false\n");
}