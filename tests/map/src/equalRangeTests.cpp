/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalRangeTests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:08:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testEqualRangeWithNumberOfElementsMap(unsigned int countPushBacks){
	std::map<int,char> original;
	std::map<int,char>::iterator it;
	ft::map<int, char> fake;
	ft::map<int, char>::iterator fit;
	std::pair<std::map<int,char>::iterator, std::map<int,char>::iterator> pairOriginal;
	ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> pairFake;

	std::cout << WARNING << "EQUAL_RANGE TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	for(unsigned int x = 1; x < countPushBacks; ++x){
		pairOriginal = original.equal_range(x);
		pairFake = fake.equal_range(x);
		it = pairOriginal.first;
		fit = pairFake.first;
		if(it->first != fit->first) {
			std::cout << KO << "[1.1]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
			return false;
		}
		if(it->second != fit->second) {
			std::cout << KO << "[1.1]DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
		if(x < countPushBacks - 1){
			it = pairOriginal.second;
			fit = pairFake.second;
			if(it->first != fit->first) {
				std::cout << KO << "[1.2]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
				return false;
			}
			if(it->second != fit->second) {
				std::cout << KO << "[1.2]DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
				return false;
			}
		}
	}
	for(unsigned int x = 0; x < countPushBacks; ++x){
		if(x % 2 == 0){
			original.erase(x);
			fake.erase(x);
		}
	}
	for(unsigned int x = 1; x < countPushBacks; ++x){
		pairOriginal = original.equal_range(x);
		pairFake = fake.equal_range(x);
		if(x < (countPushBacks - 1) || (countPushBacks - 1) % 2 != 0){
			it = pairOriginal.first;
			fit = pairFake.first;
			if(it->first != fit->first) {
				std::cout << KO << "[2.1]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
				return false;
			}
			if(it->second != fit->second) {
				std::cout << KO << "[2.1]DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
				return false;
			}
		}
		if(x < countPushBacks - 2 && original.size() >= 2){
			it = pairOriginal.second;
			fit = pairFake.second;
			if(it->first != fit->first) {
				std::cout << KO << "[2.2]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
				return false;
			}
			if(it->second != fit->second) {
				std::cout << KO << "[2.2]DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
				return false;
			}
		}
	}
	std::cout << OK << "\n";
	return true;
}

void equalRangeUnitTestsMap(t_resultTests &results){
	titleTest("EQUAL_RANGE TEST");
	_testEqualRangeWithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEqualRangeWithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseEqualRangeMap(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	manyInsertElements(countElements, map);
	for(unsigned int index = 0; index < countElements;  ++index){
		beforeClock = clock();
		map.equal_range(index);
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeMap;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double equalRangeBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int,char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseEqualRangeMap(mapSTD, "STD");
	return _benchmarkBaseEqualRangeMap(mapFT, "FT");
}