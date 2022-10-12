/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emptyTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:19:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testEmptyWithNumberOfElementsInt(unsigned int countPushBacks){
	std::vector<int> original;
	ft::vector<int> fake;
	
	std::cout << WARNING << "EMPTY TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	while (original.size() < countPushBacks){
		if (original.empty() != fake.empty()){
			std::cout << KO << "DIFFERENCE BETWEEN EMPTY" << "\n";
			return false;	
		}
		manyPushBacksInts(1, original);
		manyPushBacksInts(1, fake);
	}
	while (true){
		if (original.empty() != fake.empty()){
			std::cout << KO << "DIFFERENCE BETWEEN EMPTY" << "\n";
			return false;	
		}
		if (!original.size()){
			original.pop_back();
			fake.pop_back();	
		}
		else 
			break;
	}
	std::cout << OK << "\n";
	return true;
}

void emptyUnitTests(t_resultTests &results){
	titleTest("EMPTY TEST");
	_testEmptyWithNumberOfElementsInt(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithNumberOfElementsInt(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double _benchmarkBaseEmpty(genericVector vector, std::string typeVector){
	unsigned int countElements = 100000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(vector.size() < countElements){
		beforeClock = clock();
		vector.empty();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
		manyPushBacksInts(1, vector);
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << (!typeVector.compare("STD") ? "STD" : "FT");
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double emptyBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseEmpty(vectorSTD, "STD");
	return _benchmarkBaseEmpty(vectorFT, "FT");
}