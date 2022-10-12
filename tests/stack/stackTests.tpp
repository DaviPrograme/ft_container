/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 05:32:59 by coder            ###   ########.fr       */
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

template<class stackPerson>
void stackTests(stackPerson stack){
	stack.size();
	std::cout << "CONSTRUCTOR VOID: \n";
	stackPerson stackVoid;
	std::cout << "size: " << stackVoid.size();

	std::cout << "PUSH: \n";
	for(size_t x = 0; x < 125; ++x)
		stackVoid.push(person("Tarcisio", x));
	std::cout << "size: " << stackVoid.size();

	std::cout << "POP: \n";
	for(size_t x = 0; x < 50; ++x)
		stackVoid.pop();
	std::cout << "size: " << stackVoid.size();

	std::cout << "EMPTY: \n";
	stackPerson stackTeste;
	std::cout << (stackTeste.empty() ? "true\n" : "false\n");
	std::cout << (stackVoid.empty() ? "true\n" : "false\n\n");
	
	std::cout << "TOP: \n";
	while(stackVoid.size() > 1){
		std::cout << "name: " << stackVoid.top().getName();
		std::cout << "   years: " << stackVoid.top().getYears() << "\n\n";
		stackVoid.pop();
	}

	

	std::cout << "RELATIONAL OPERATOR: \n";
	std::cout << "[stackFull > stackEmpty]: " << (stackVoid > stackTeste ? "true\n" : "false\n");
	std::cout << "[stackFull >= stackEmpty]: " << (stackVoid >= stackTeste ? "true\n" : "false\n");
	std::cout << "[stackFull < stackEmpty]: " << (stackVoid < stackTeste ? "true\n" : "false\n");
	std::cout << "[stackFull <= stackEmpty]: " << (stackVoid <= stackTeste ? "true\n" : "false\n");
	std::cout << "[stackFull == stackEmpty]: " << (stackVoid == stackTeste ? "true\n" : "false\n");
	std::cout << "[stackFull != stackEmpty]: " << (stackVoid != stackTeste ? "true\n" : "false\n");
		
	
	
}