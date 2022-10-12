/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:12:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testSizeWithNumberOfElements(unsigned int countPushBacks){
	std::map<int, char> original;
	ft::map<int, char> fake;
	std::cout << WARNING << "SIZE TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	if (original.size() != fake.size()) {
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}



void sizeUnitTestsMap(t_resultTests &results){
	titleTest("SIZE TEST");
	_testSizeWithNumberOfElements(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testSizeWithNumberOfElements(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

double _benchmarkBaseSizeMap(std::map<int, char> &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	std::pair<int, char> pair;
	unsigned int countElements = 10000;

	while(countElements){
		pair = std::make_pair(countElements, '!' + (countElements % 94));
		map.insert(pair);
		beforeClock = clock();
		map.size();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
		--countElements;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeMap;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ;
	return time;
}

double _benchmarkBaseSizeMap(ft::map<int, char> &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	ft::pair<int, char> pair;
	unsigned int countElements = 10000;

	while(countElements){
		pair = ft::make_pair(countElements, '!' + (countElements % 94));
		map.insert(pair);
		beforeClock = clock();
		map.size();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
		--countElements;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeMap;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ;
	return time;
}

double sizeBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseSizeMap(mapSTD, "STD");
	return _benchmarkBaseSizeMap(mapFT, "FT");
}
