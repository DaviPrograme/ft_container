/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:09:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testFindWithNumberOfElementsMap(unsigned int countPushBacks){
	std::map<int,char> original;
	std::map<int,char>::iterator it;
	ft::map<int, char> fake;
	ft::map<int, char>::iterator fit;

	std::cout << WARNING << "FIND TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	for(unsigned int x = 0; x < countPushBacks; ++x){
		it = original.find(x);
		fit = fake.find(x);
		if(it->first != fit->first) {
			std::cout << KO << "DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
			return false;
		}
		if(it->second != fit->second) {
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void findUnitTestsMap(t_resultTests &results){
	titleTest("FIND TEST");
	_testFindWithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testFindWithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseFindMap(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	manyInsertElements(countElements, map);
	for(unsigned int index = 0; index < countElements;  ++index){
		beforeClock = clock();
		map.find(index);
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

double findBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int,char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseFindMap(mapSTD, "STD");
	return _benchmarkBaseFindMap(mapFT, "FT");
}