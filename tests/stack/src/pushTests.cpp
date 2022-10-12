/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 00:16:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stackTests.hpp"

bool _testPushWithNumberOfElementsIntStack(unsigned int countPushBacks){
	std::stack<int> original;
	ft::stack<int> fake;
	std::cout << WARNING << "PUSH TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	for (unsigned int x = 0; x < countPushBacks;  ++x){
		original.push(x);
		fake.push(x);
	}
	while (original.size()) {
		if(original.top() != fake.top()){
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
		original.pop();
		fake.pop();
	}
	std::cout << OK << "\n";
	return true;
}

void pushUnitTestsStack(t_resultTests &results){
	titleTest("PUSH TEST");
	_testPushWithNumberOfElementsIntStack(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushWithNumberOfElementsIntStack(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericStack>
double _benchmarkBasePushStack(genericStack stack, std::string typeStack){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 100000;

	while(stack.size() < countElements){
		beforeClock = clock();
		stack.push(42);
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

double pushBenchmarkStack(std::string typeStack){
	std::stack<int> stackSTD;
	ft::stack<int> stackFT;

	if(!typeStack.compare("STD"))
		return _benchmarkBasePushStack(stackSTD, "STD");
	return _benchmarkBasePushStack(stackFT, "FT");
}