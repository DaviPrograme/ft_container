/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emptyTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 00:21:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stackTests.hpp"

bool _testEmptyWithNumberOfElementsIntStack(unsigned int countPushBacks){
	std::stack<int> original;
	ft::stack<int> fake;
	
	std::cout << WARNING << "EMPTY TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	while (original.size() < countPushBacks){
		if (original.empty() != fake.empty()){
			std::cout << KO << "DIFFERENCE BETWEEN EMPTY" << "\n";
			return false;	
		}
		original.push(42);
		fake.push(42);
	}
	while (true){
		if (original.empty() != fake.empty()){
			std::cout << KO << "DIFFERENCE BETWEEN EMPTY" << "\n";
			return false;	
		}
		if (!original.size()){
			original.pop();
			fake.pop();	
		}
		else 
			break;
	}
	std::cout << OK << "\n";
	return true;
}

void emptyUnitTestsStack(t_resultTests &results){
	titleTest("EMPTY TEST");
	_testEmptyWithNumberOfElementsIntStack(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsIntStack(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericStack>
double _benchmarkBaseEmptyStack(genericStack stack, std::string typeStack){
	unsigned int countElements = 100000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(stack.size() < countElements){
		beforeClock = clock();
		stack.empty();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
		stack.push(42);
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << (!typeStack.compare("STD") ? "STD" : "FT");
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double emptyBenchmarkStack(std::string typeStack){
	std::stack<int> stackSTD;
	ft::stack<int> stackFT;
	
	if (!typeStack.compare("STD"))
		return _benchmarkBaseEmptyStack(stackSTD, "STD");
	return _benchmarkBaseEmptyStack(stackFT, "FT");
}