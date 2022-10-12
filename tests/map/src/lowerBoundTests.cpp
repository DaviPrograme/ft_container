/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowerBoundTests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:11:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testLowerBoundWithNumberOfElementsMap(unsigned int countPushBacks){
	std::map<int,char> original;
	std::map<int,char>::iterator it;
	ft::map<int, char> fake;
	ft::map<int, char>::iterator fit;

	std::cout << WARNING << "LOWER_BOUND TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	for(unsigned int x = 1; x < countPushBacks; ++x){
		it = original.lower_bound(x);
		fit = fake.lower_bound(x);
		if(it->first != fit->first) {
			std::cout << KO << "[1]DIVERGENCE BETWEEN KEY VALUES" << WHITE << x << "\n";
			return false;
		}
		if(it->second != fit->second) {
			std::cout << KO << "[1]DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	for(unsigned int x = 0; x < countPushBacks; ++x){
		if(x % 2 == 0){
			original.erase(x);
			fake.erase(x);
		}
	}
	for(unsigned int x = 1; x < countPushBacks; ++x){
		if(x == (countPushBacks - 1) && (countPushBacks - 1) % 2 == 0)
			continue;
		it = original.lower_bound(x);
		fit = fake.lower_bound(x);
		if(it->first != fit->first) {
			std::cout << KO << "[2]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
			return false;
		}
		if(it->second != fit->second) {
			std::cout << KO << "[2]DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void lowerBoundUnitTestsMap(t_resultTests &results){
	titleTest("LOWER_BOUND TEST");
	_testLowerBoundWithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testLowerBoundWithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseLowerBoundMap(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	manyInsertElements(countElements, map);
	for(unsigned int index = 0; index < countElements;  ++index){
		beforeClock = clock();
		map.lower_bound(index);
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

double lowerBoundBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int,char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseLowerBoundMap(mapSTD, "STD");
	return _benchmarkBaseLowerBoundMap(mapFT, "FT");
}