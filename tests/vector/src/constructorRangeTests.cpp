/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructorRangeTests.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/10 15:46:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testConstructorRangeVector(size_t countElements){
	std::vector<int> originalSource;
	ft::vector<int> fakeSource;

	for(size_t x = 0; x < countElements; ++x){
		originalSource.push_back(x);
		fakeSource.push_back(x);
	}
	std::vector<int> original(originalSource.begin(), originalSource.end());
	ft::vector<int> fake(fakeSource.begin(), fakeSource.end());
	std::cout << WARNING << "CONSTRUCTOR RANGE WITH " << countElements << " ELEMENT(S): " << WHITE;
	if (original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << "\n";
		return false;	
	}
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if (!compareElementsVectors(original, fake)) {
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

void constructorRangeUnitTests(t_resultTests &results){
	titleTest("CONSTRUCTOR RANGE TEST");
	_testConstructorRangeVector(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeVector(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double baseLoopConstructorRange(genericVector &vectorSource){
	clock_t beforeClock;
	clock_t afterClock;

	beforeClock = clock();
	genericVector vectorDestiny(vectorSource.begin(), vectorSource.end());
	afterClock = clock();
	return afterClock - beforeClock;
}

template<class genericVector>
double _benchmarkConstructorRange(genericVector &vector, std::string typeVector){
	double time = 0;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 1000;
	
	for(unsigned int x = 0; x < countElements; ++x)
		vector.push_back(x);
	while(--countElements)
		accumulatedClock += baseLoopConstructorRange(vector);
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeVector;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double constructorRangeBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;

	if(!typeVector.compare("STD"))
		return _benchmarkConstructorRange(vectorSTD, "STD");
	return _benchmarkConstructorRange(vectorFT, "FT");
}