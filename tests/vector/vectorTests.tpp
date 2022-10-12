/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/11 11:02:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class person {
	public:
		std::string _name;
		size_t _years;
		person(): _name("default"), _years(1980){};
		person(std::string name, size_t years): _name(name), _years(years){};
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

template<class vectorPerson>
void vectorTests(vectorPerson vector){
	vector.size();
	std::cout << "CONSTRUCTOR VOID: \n";
	vectorPerson vectorVoid;
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n\n";
	
	std::cout << "CONSTRUCTOR FILL: \n";
	vectorPerson vectorFill(100, person());
	std::cout << "size: " << vectorFill.size();
	std::cout << " capacity: " << vectorFill.capacity() << "\n\n";

	std::cout << "CONSTRUCTOR RANGE: \n";
	vectorPerson vectorRange(vectorFill.begin(), vectorFill.end());
	std::cout << "size: " << vectorRange.size();
	std::cout << " capacity: " << vectorRange.capacity() << "\n\n";

	std::cout << "CONSTRUCTOR COPY: \n";
	vectorPerson vectorCopy(vectorRange);
	std::cout << "size: " << vectorCopy.size();
	std::cout << " capacity: " << vectorCopy.capacity() << "\n\n";

	std::cout << "PUSH BACKS: \n";
	for(size_t x = 0; x < 125; ++x)
		vectorVoid.push_back(person("Tarcisio", x));
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n\n";

	std::cout << "POP BACKS: \n";
	for(size_t x = 0; x < 50; ++x)
		vectorVoid.pop_back();
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n\n";

	std::cout << "MAX SIZE: \n";
	std::cout << "value: " << vectorVoid.max_size() << "\n\n";

	std::cout << "RESIZE: \n";
	std::cout << "[increasing capacity]:\n";
	vectorVoid.resize(vectorVoid.capacity() * 3);
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n";
	std::cout << "[decreasing capacity]:\n";
	vectorVoid.resize(15);
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n\n";
	
	std::cout << "EMPTY: \n";
	vectorPerson vecTeste;
	std::cout << (vecTeste.empty() ? "true\n" : "false\n");
	std::cout << (vectorVoid.empty() ? "true\n" : "false\n\n");
	
	std::cout << "RESERVE: \n";
	std::cout << "[less than capacity]:\n";
	vectorVoid.reserve(0);
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n";
	std::cout << "[greater than capacity]:\n";
	vectorVoid.reserve(vectorVoid.capacity() + 5);
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n\n";

	std::cout << "OPERATOR[]: \n";
	for(size_t x = 0; x < vectorVoid.size(); ++x){
		std::cout << "name: " << vectorVoid[x].getName();
		std::cout << "   years: " << vectorVoid[x].getYears() << "\n";
	}

	std::cout << "\nAT: \n";
	for(size_t x = 0; x < vectorVoid.size(); ++x){
		std::cout << "name: " << vectorVoid.at(x).getName();
		std::cout << "   years: " << vectorVoid.at(x).getYears() << "\n";
	}

	std::cout << "\nFRONT: \n";
	std::cout << "name: " << vectorVoid.front().getName();
	std::cout << "   years: " << vectorVoid.front().getYears() << "\n\n";

	std::cout << "BACK: \n";
	std::cout << "name: " << vectorVoid.back().getName();
	std::cout << "   years: " << vectorVoid.back().getYears() << "\n\n";

	std::cout << "ASSIGN: \n";
	vectorFill.assign(5, person("RONALDINHO", 10));
	std::cout << "size: " << vectorFill.size();
	std::cout << " capacity: " << vectorFill.capacity() << "\n\n";

	std::cout << "INSERT: \n";
	vectorVoid.insert(vectorVoid.begin() + (vectorVoid.size() / 2), person("ROGERIO", 42));
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n\n";

	std::cout << "ERASE: \n";
	vectorVoid.erase(vectorVoid.end() - 1);
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n\n";

	std::cout << "SWAP: \n";
	std::cout << "[first exchange]\n";
	swap(vectorVoid, vectorFill);
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n";
	std::cout << "[undoing the exchange]\n";
	swap(vectorVoid, vectorFill);
	std::cout << "size: " << vectorVoid.size();
	std::cout << " capacity: " << vectorVoid.capacity() << "\n\n";


	std::cout << "CLEAR: \n";
	std::cout << "[before]\n";
	std::cout << "size: " << vectorFill.size();
	std::cout << " capacity: " << vectorFill.capacity() << "\n";
	vectorFill.clear();
	std::cout << "[after]\n";
	std::cout << "size: " << vectorFill.size();
	std::cout << " capacity: " << vectorFill.capacity() << "\n\n";

	std::cout << "\nBEGIN: \n";
	typename vectorPerson::iterator it;
	it = vectorVoid.begin();
	while(it != vectorVoid.end()){
		std::cout << "name: " << it->getName();
		std::cout << "   years: " << it->getYears() << "\n";
		++it;
	}

	std::cout << "\nEND: \n";
	it = vectorVoid.end();
	while(it != vectorVoid.begin() - 1){
		std::cout << "name: " << it->getName();
		std::cout << "   years: " << it->getYears() << "\n";
		--it;
	}

	std::cout << "\nRBEGIN: \n";
	typename vectorPerson::reverse_iterator rit;
	rit = vectorVoid.rbegin();
	while(rit != vectorVoid.rend()){
		std::cout << "namep: " << rit->getName();
		std::cout << "   yearsp: " << rit->getYears() << "\n";
		++rit;
	}

	std::cout << "\nREND: \n";
	rit = vectorVoid.rend();
	while(--rit != vectorVoid.rbegin() - 1){
		std::cout << "name: " << rit->getName();
		std::cout << "   years: " << rit->getYears() << "\n";
	}
	
	std::cout << "DATA: ";
	person *ptr = vectorVoid.data();
	for(unsigned int x = 0; x < vectorVoid.size(); ++x){
		std::cout << "name: " << ptr[x].getName();
		std::cout << "   years: " << ptr[x].getYears() << "\n";
	}
	
	std::cout << "RELATIONAL OPERATOR: \n";
	vectorPerson vectorEmpty;
	vectorPerson vectorFull(10, person());
	std::cout << "[vectorFull > vectorEmpty]: " << (vectorFull > vectorEmpty ? "true\n" : "false\n");
	std::cout << "[vectorFull >= vectorEmpty]: " << (vectorFull >= vectorEmpty ? "true\n" : "false\n");
	std::cout << "[vectorFull < vectorEmpty]: " << (vectorFull < vectorEmpty ? "true\n" : "false\n");
	std::cout << "[vectorFull <= vectorEmpty]: " << (vectorFull <= vectorEmpty ? "true\n" : "false\n");
	std::cout << "[vectorFull == vectorEmpty]: " << (vectorFull == vectorEmpty ? "true\n" : "false\n");
	std::cout << "[vectorFull != vectorEmpty]: " << (vectorFull != vectorEmpty ? "true\n" : "false\n");
	
}