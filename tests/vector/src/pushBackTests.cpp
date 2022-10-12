/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushBackTests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:26:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testPushBacksWithNumberOfElementsInt(unsigned int countPushBacks){
	std::vector<int> original;
	ft::vector<int> fake;
	std::cout << WARNING << "PUSHBACK TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyPushBacksInts(countPushBacks, original);
	copyElementsVector(original, fake);
	if (!compareElementsVectors(original, fake)) {
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

void pushBackUnitTests(t_resultTests &results){
	titleTest("PUSH_BACK TEST");
	_testPushBacksWithNumberOfElementsInt(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testPushBacksWithNumberOfElementsInt(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double _benchmarkBasePushBack(genericVector vector, std::string typeVector){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 100000;

	while(vector.size() < countElements){
		beforeClock = clock();
		vector.push_back(42);
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeVector;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double pushBackBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;

	if(!typeVector.compare("STD"))
		return _benchmarkBasePushBack(vectorSTD, "STD");
	return _benchmarkBasePushBack(vectorFT, "FT");
}