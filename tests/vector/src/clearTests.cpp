/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:18:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _clearTest(unsigned int countPushBacks){
	std::vector<int> original;
	std::vector<int>::iterator it;
	ft::vector<int> fake;
	
	std::cout << WARNING << "CLEAR TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyPushBacksInts(countPushBacks, original);
	manyPushBacksInts(countPushBacks, fake);
	it = original.begin();
	original.clear();
	fake.clear();
	
	if(original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;	
	}
	std::cout << OK << "\n";
	return true;
}

void clearUnitTests(t_resultTests &results){
	titleTest("CLEAR TEST");
	_clearTest(1) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(2) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(3) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(4) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(5) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(6) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(7) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(8) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(9) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(100) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(500) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTest(1000) ? results.countRightTests += 1 : results.countWrongTests += 1;
}

template<class genericVector>
double _benchmarkBaseClear(genericVector vector, std::string typeVector){
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(--countElements){
		manyPushBacksInts(countElements, vector);
		beforeClock = clock();
		vector.clear();
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

double clearBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseClear(vectorSTD, "STD");
	return _benchmarkBaseClear(vectorFT, "FT");
}