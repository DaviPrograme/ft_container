/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/04 00:33:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testSizeWithNumberOfElementsInt(unsigned int countPushBacks){
	std::vector<int> original;
	ft::vector<int> fake;
	
	std::cout << WARNING << "SIZE TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	while (original.size() < countPushBacks){
		if (original.size() != fake.size()){
			std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
			return false;	
		}
		manyPushBacksInts(1, original);
		manyPushBacksInts(1, fake);
	}
	while (true){
		if (original.size() != fake.size()){
			std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
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

void sizeUnitTests(t_resultTests &results){
	titleTest("SIZE TEST");
	_testSizeWithNumberOfElementsInt(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElementsInt(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double _benchmarkBaseSize(genericVector vector, std::string typeVector){
	unsigned int countElements = 100000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(vector.size() < countElements){
		manyPushBacksInts(1, vector);
		beforeClock = clock();
		vector.size();
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

double sizeBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseSize(vectorSTD, "STD");
	return _benchmarkBaseSize(vectorFT, "FT");
}