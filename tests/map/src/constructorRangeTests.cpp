/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructorRangeTests.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 22:04:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testConstructorRangeMap(unsigned int countPushBacks){
	ft::map<int, char> source;

	std::cout << WARNING << "CONSTRUCTOR RANGE TEST WITH " << countPushBacks << " ELEMENT(S): "<< WHITE;
	manyInsertElements(countPushBacks, source);
	ft::map<int, char> destinyFake(source.begin(), source.end());
	if (source.size() != destinyFake.size()){
		std::cout << KO << "[1]DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;
	}
	for(unsigned int x = 0; x < countPushBacks; ++x){
		if(source.at(x) != destinyFake.at(x)){
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void constructorRangeUnitTestsMap(t_resultTests &results){
	titleTest("CONSTRUCTOR RANGE TEST");
	_testConstructorRangeMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorRangeMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double baseLoopConstructorRange(genericMap &map){
	clock_t beforeClock;
	clock_t afterClock;
	genericMap source;
	typename genericMap::iterator itStart;
	typename genericMap::iterator itEnd;

	manyInsertElements(1, source);
	itStart = source.begin();
	itEnd = source.end();
	beforeClock = clock();
	genericMap mapTeste(itStart, itEnd);
	afterClock = clock();
	map.size();
	return afterClock - beforeClock;
}

template<class genericMap>
double _benchmarkConstructorRange(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 1000;

	while(--countElements)
		accumulatedClock += baseLoopConstructorRange(map);
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeMap;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double constructorRangeBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkConstructorRange(mapSTD, "STD");
	return _benchmarkConstructorRange(mapFT, "FT");
}