/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructorCopyTests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 22:04:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testConstructorCopyMap(unsigned int countPushBacks){
	ft::map<int, char> sourceFake;

	std::cout << WARNING << "CONSTRUCTOR COPY TEST WITH " << countPushBacks << " ELEMENT(S): "<< WHITE;
	manyInsertElements(countPushBacks, sourceFake);
	ft::map<int, char> destinyFake(sourceFake);
	if (sourceFake.size() != destinyFake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;
	}
	for(unsigned int x = 0; x < countPushBacks; ++x){
		if(sourceFake.at(x) != destinyFake.at(x)){
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void constructorCopyUnitTestsMap(t_resultTests &results){
	titleTest("CONSTRUCTOR COPY TEST");
	_testConstructorCopyMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorCopyMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double baseLoopConstructorCopy(genericMap &map){
	clock_t beforeClock;
	clock_t afterClock;
	genericMap source;

	manyInsertElements(1, source);
	beforeClock = clock();
	genericMap mapTeste(source);
	afterClock = clock();
	map.size();
	return afterClock - beforeClock;
}

template<class genericMap>
double _benchmarkConstructorCopy(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 1000;

	while(--countElements)
		accumulatedClock += baseLoopConstructorCopy(map);
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeMap;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double constructorCopyBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkConstructorCopy(mapSTD, "STD");
	return _benchmarkConstructorCopy(mapFT, "FT");
}