/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacityTests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:14:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testCapacityWithNumberOfElementsInt(unsigned int countPushBacks){
	std::vector<int> original;
	ft::vector<int> fake;
	
	std::cout << WARNING << "CAPACITY TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	while (original.size() < countPushBacks){
		if (original.capacity() != fake.capacity()){
			std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << "\n";
			return false;	
		}
		manyPushBacksInts(1, original);
		manyPushBacksInts(1, fake);
	}
	while (true){
		if (original.capacity() != fake.capacity()){
			std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << "\n";
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

void capacityUnitTests(t_resultTests &results){
	titleTest("CAPACITY TEST");
	_testCapacityWithNumberOfElementsInt(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testCapacityWithNumberOfElementsInt(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double _benchmarkBaseCapacity(genericVector vector, std::string typeVector){
	unsigned int countElements = 100000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(vector.size() < countElements){
		manyPushBacksInts(1, vector);
		beforeClock = clock();
		vector.capacity();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << (!typeVector.compare("STD") ? "STD" : "FT");
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double capacityBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseCapacity(vectorSTD, "STD");
	return _benchmarkBaseCapacity(vectorFT, "FT");
}