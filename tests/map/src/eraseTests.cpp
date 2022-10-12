/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eraseTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:09:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testErase1WithNumberOfElementsMap(unsigned int countPushBacks){
	std::map<int,char> original;
	ft::map<int, char> fake;
	unsigned int count = 0;

	std::cout << WARNING << "TEST ERASE(iterator) WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	while(original.size()){
		if (original.size() != fake.size()){
			std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
			return false;	
		}
		for(unsigned int x = count; original.size() && x < countPushBacks; ++x){
			if(original.at(x) != fake.at(x)){
				std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
				return false;
			}
		}
		original.erase(original.begin());
		fake.erase(fake.begin());
		++count;
	}
	std::cout << OK << "\n";
	return true;
}

bool _testErase2WithNumberOfElementsMap(unsigned int countPushBacks){
	std::map<int,char> original;
	ft::map<int, char> fake;
	unsigned int count = 0;

	std::cout << WARNING << "TEST ERASE(key_type) WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	while(original.size()){
		if (original.size() != fake.size()){
			std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
			return false;	
		}
		for(unsigned int x = count; original.size() && x < countPushBacks; ++x){
			if(original.at(x) != fake.at(x)){
				std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
				return false;
			}
		}
		original.erase(count);
		fake.erase(count);
		++count;
	}
	std::cout << OK << "\n";
	return true;
}

bool _testErase3WithNumberOfElementsMap(unsigned int countPushBacks){
	std::map<int,char> original;
	std::map<int,char>::iterator itStartOriginal;
	std::map<int,char>::iterator itEndOriginal;
	ft::map<int, char> fake;
	ft::map<int,char>::iterator itStartFake;
	ft::map<int,char>::iterator itEndFake;
	unsigned int count = 0;

	std::cout << WARNING << "TEST ERASE(iterator, iterator) WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	while(original.size()){
		if (original.size() != fake.size()){
			std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
			return false;	
		}
		for(unsigned int x = count; original.size() && x < countPushBacks; ++x){
			if(original.at(x) != fake.at(x)){
				std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
				return false;
			}
		}
		itStartOriginal = original.begin();
		itEndOriginal = original.begin();
		++itEndOriginal;
		itStartFake = fake.begin();
		itEndFake = fake.begin();
		++itEndFake;
		original.erase(itStartOriginal, itEndOriginal);
		fake.erase(itStartFake, itEndFake);
		++count;
	}
	std::cout << OK << "\n";
	return true;
}

void eraseUnitTestsMap(t_resultTests &results){
	titleTest("ERASE TEST");
	_testErase1WithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase1WithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;

	_testErase2WithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase2WithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	
	_testErase3WithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testErase3WithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseErase1Map(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	manyInsertElements(countElements, map);
	for(unsigned int index = 0; index < countElements;  ++index){
		beforeClock = clock();
		map.erase(map.begin());
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

double erase1BenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int,char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseErase1Map(mapSTD, "STD");
	return _benchmarkBaseErase1Map(mapFT, "FT");
}

template<class genericMap>
double _benchmarkBaseErase2Map(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	manyInsertElements(countElements, map);
	for(unsigned int index = 0; index < countElements;  ++index){
		beforeClock = clock();
		map.erase(index);
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

double erase2BenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int,char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseErase2Map(mapSTD, "STD");
	return _benchmarkBaseErase2Map(mapFT, "FT");
}

template<class genericMap>
double _benchmarkBaseErase3Map(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	typename genericMap::iterator itStart;
	typename genericMap::iterator itEnd;
	unsigned int countElements = 10000;

	
	manyInsertElements(countElements, map);
	for(unsigned int index = 0; index < countElements;  ++index){
		itStart = map.begin();
		itEnd = map.begin();
		++itEnd;
		beforeClock = clock();
		map.erase(itStart, itEnd);
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

double erase3BenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int,char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseErase3Map(mapSTD, "STD");
	return _benchmarkBaseErase3Map(mapFT, "FT");
}