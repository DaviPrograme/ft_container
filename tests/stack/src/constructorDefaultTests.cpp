/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructorDefaultTests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/09 22:50:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stackTests.hpp"

bool _testConstructorDefaultStack(void){
	std::stack<int> original;
	ft::stack<int> fake;
	std::cout << WARNING << "CONSTRUCTOR DEFAULT TEST: " << WHITE;
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	std::cout << OK << "\n";
	return true;
}

void constructorDefaultUnitTestsStack(t_resultTests &results){
	titleTest("CONSTRUCTOR DEFAULT TEST");
	_testConstructorDefaultStack() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericStack>
double baseLoopConstructorDefault(genericStack &stack){
	clock_t beforeClock;
	clock_t afterClock;

	beforeClock = clock();
	genericStack vectorTeste;
	afterClock = clock();
	stack.size();
	return afterClock - beforeClock;
}

template<class genericStack>
double _benchmarkConstructorDefaultStack(genericStack stack, std::string typeMap){
	double time = 0;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 100000;

	while(--countElements)
		accumulatedClock += baseLoopConstructorDefault(stack);
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeMap;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double constructorDefaultBenchmarkStack(std::string typeMap){
	std::stack<int> stackSTD;
	ft::stack<int> stackFT;

	if(!typeMap.compare("STD"))
		return _benchmarkConstructorDefaultStack(stackSTD, "STD");
	return _benchmarkConstructorDefaultStack(stackFT, "FT");
}