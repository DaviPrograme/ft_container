/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 00:20:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stackTests.hpp"

bool _testSizeWithNumberOfElementsIntStack(unsigned int countPushBacks){
	std::stack<int> original;
	ft::stack<int> fake;
	
	std::cout << WARNING << "SIZE TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	while (original.size() < countPushBacks){
		if (original.size() != fake.size()){
			std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
			return false;	
		}
		original.push(42);
		fake.push(42);
	}
	while (true){
		if (original.size() != fake.size()){
			std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
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

void sizeUnitTestsStack(t_resultTests &results){
	titleTest("SIZE TEST");
	_testSizeWithNumberOfElementsIntStack(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsIntStack(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericSatck>
double _benchmarkBaseSizeStack(genericSatck stack, std::string typeStack){
	unsigned int countElements = 100000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(stack.size() < countElements){
		stack.push(42);
		beforeClock = clock();
		stack.size();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeStack;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double sizeBenchmarkStack(std::string typeStack){
	std::stack<int> stackSTD;
	ft::stack<int> stackFT;
	
	if (!typeStack.compare("STD"))
		return _benchmarkBaseSizeStack(stackSTD, "STD");
	return _benchmarkBaseSizeStack(stackFT, "FT");
}