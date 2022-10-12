/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructorDefaultTests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:07:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testConstructorDefaultMap(unsigned int countPushBacks){
	std::map<int, char> original;
	ft::map<int, char> fake;
	std::cout << WARNING << "CONSTRUCTOR DEFAULT TEST WITH " << countPushBacks << " ELEMENT(S): "<< WHITE;
	if (original.size() != fake.size()){
		std::cout << KO << "[1]DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;
	}
	manyInsertElements(countPushBacks, original, fake);
	if (original.size() != fake.size()){
		std::cout << KO << "[2]DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;
	}
	for(unsigned int x = 0; x < countPushBacks; ++x){
		if(original.at(x) != fake.at(x)){
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void constructorDefaultUnitTestsMap(t_resultTests &results){
	titleTest("CONSTRUCTOR DEFAULT TEST");
	_testConstructorDefaultMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorDefaultMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double baseLoopConstructorDefault(genericMap &map){
	clock_t beforeClock;
	clock_t afterClock;

	beforeClock = clock();
	genericMap mapTeste;
	afterClock = clock();
	map.size();
	return afterClock - beforeClock;
}

template<class genericMap>
double _benchmarkConstructorDefault(genericMap map, std::string typeMap){
	double time = 0;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	while(--countElements)
		accumulatedClock += baseLoopConstructorDefault(map);
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeMap;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double constructorDefaultBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkConstructorDefault(mapSTD, "STD");
	return _benchmarkConstructorDefault(mapFT, "FT");
}