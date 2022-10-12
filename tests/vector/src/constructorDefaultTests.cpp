/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructorDefaultTests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/10 15:10:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testConstructorDefaultVector(void){
	std::vector<int> original;
	ft::vector<int> fake;
	std::cout << WARNING << "CONSTRUCTOR DEFAULT TEST: " << WHITE;
	if (original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << "\n";
		return false;	
	}
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	std::cout << OK << "\n";
	return true;
}

void constructorDefaultUnitTests(t_resultTests &results){
	titleTest("CONSTRUCTOR DEFAULT TEST");
	_testConstructorDefaultVector() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double baseLoopConstructorDefault(genericVector &vector){
	clock_t beforeClock;
	clock_t afterClock;

	beforeClock = clock();
	genericVector vectorTeste;
	afterClock = clock();
	vector.size();
	return afterClock - beforeClock;
}

template<class genericVector>
double _benchmarkConstructorDefault(genericVector vector, std::string typeVector){
	double time = 0;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 100000;

	while(--countElements)
		accumulatedClock += baseLoopConstructorDefault(vector);
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeVector;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double constructorDefaultBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;

	if(!typeVector.compare("STD"))
		return _benchmarkConstructorDefault(vectorSTD, "STD");
	return _benchmarkConstructorDefault(vectorFT, "FT");
}