/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valueCompTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:13:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testValueCompWithNumberOfElements(unsigned int countPushBacks){
	std::map<int, char> original;
	std::map<int, char>::iterator itStart;
	std::map<int, char>::iterator itEnd;
	ft::map<int, char> fake;
	ft::map<int, char>::iterator fitStart;
	ft::map<int, char>::iterator fitEnd;
	unsigned int limit = countPushBacks / 2;

	std::cout << WARNING << "VALUE_COMP TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	itStart = original.begin();
	itEnd = original.end();
	fitStart = fake.begin();
	fitEnd = fake.end();
	for(unsigned int x = 0; x < limit; ++x){
		--itEnd;
		--fitEnd;
		if(original.value_comp()(*itStart, *itEnd) != fake.value_comp()(*fitStart, *fitEnd)){
			std::cout << KO << "[1]DIFFERENCE IN COMPARISON" << WHITE << "\n";
			return false;
		}
		if(original.value_comp()(*itEnd, *itStart) != fake.value_comp()(*fitEnd, *fitStart)){
			std::cout << KO << "[2]DIFFERENCE IN COMPARISON" << WHITE << "\n";
			return false;
		}
		if(original.value_comp()(*itStart, *itStart) != fake.value_comp()(*fitStart, *fitStart)){
			std::cout << KO << "[3]DIFFERENCE IN COMPARISON" << WHITE << "\n";
			return false;
		}
		++itStart;
		++fitStart;
	}
	std::cout << OK << "\n";
	return true;
}

void valueCompUnitTestsMap(t_resultTests &results){
	titleTest("VALUE_COMP TEST");
	_testValueCompWithNumberOfElements(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testValueCompWithNumberOfElements(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseValueCompMap(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 20000;
	unsigned int limit = countElements / 2;
	typename genericMap::iterator itStart;
	typename genericMap::iterator itEnd;

	manyInsertElements(countElements, map);
	itStart = map.begin();
	itEnd = map.end();
	while(limit){
		--itEnd;
		beforeClock = clock();
		map.value_comp()(*itStart, *itEnd);
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
		--limit;
		++itStart;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeMap;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ;
	return time;
}

double valueCompBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseValueCompMap(mapSTD, "STD");
	return _benchmarkBaseValueCompMap(mapFT, "FT");
}
