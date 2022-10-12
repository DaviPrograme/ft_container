/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 00:19:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stackTests.hpp"

bool _testTopWithNumberOfElementsIntStack(unsigned int countPushBacks){
	std::stack<int> original;
	ft::stack<int> fake;
	std::cout << WARNING << "TOP TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	for(unsigned int x = 1; x <= countPushBacks; ++x){
		original.push(x);
		fake.push(x);
		if (original.top() != fake.top()) {
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void topUnitTestsStack(t_resultTests &results){
	titleTest("TOP TEST");
	_testTopWithNumberOfElementsIntStack(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testTopWithNumberOfElementsIntStack(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericStack>
double _benchmarkBaseTopStack(genericStack stack, std::string typeStack){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 100000;

	for(unsigned int x = 0; x < countElements; ++x)
		stack.push(x);
	for(unsigned int index = 0; index < countElements;  ++index){
		beforeClock = clock();
		stack.top();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
		stack.pop();
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeStack;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double topBenchmarkStack(std::string typeStack){
	std::stack<int> stackSTD;
	ft::stack<int> stackFT;

	if(!typeStack.compare("STD"))
		return _benchmarkBaseTopStack(stackSTD, "STD");
	return _benchmarkBaseTopStack(stackFT, "FT");
}