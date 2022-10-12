/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 00:11:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stackTests.hpp"

bool _testPopWithNumberOfElementsIntStack(unsigned int countPushBacks){
	std::stack<int> original;
	ft::stack<int> fake;
	
	std::cout << WARNING << "POP TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	for (unsigned int x = 0; x < countPushBacks;  ++x){
		original.push(x);
		fake.push(x);
	}
	while (original.size())  {
		if (original.top() != fake.top()) {
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
		original.pop();
		fake.pop();	
	}
	std::cout << OK << "\n";
	return true;
}

void popUnitTestsStack(t_resultTests &results){
	titleTest("POP TEST");
	_testPopWithNumberOfElementsIntStack(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPopWithNumberOfElementsIntStack(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericStack>
double _benchmarkBasePopStack(genericStack stack, std::string typeStack){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 100000;

	for (unsigned int x = 0; x < countElements;  ++x)
		stack.push(x);
	while(stack.size()){
		beforeClock = clock();
		stack.pop();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeStack;
	std::cout << ": " << GREEN;
	std::cout << std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double popBackBenchmarkStack(std::string typeStack){
	std::stack<int> stackSTD;
	ft::stack<int> stackFT;

	if(typeStack.compare("STD"))
		return _benchmarkBasePopStack(stackSTD, "STD");
	return _benchmarkBasePopStack(stackFT, "FT");
}
