/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:30:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testInsertFirstSignatureWithNumberOfElements(unsigned int countPushBacks){
	std::map<int, char> original;
	ft::map<int, char> fake;
	std::cout << WARNING << "TEST INSERT (value_type&) WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	if (!compareElementsMap(original, fake)) {
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}


bool _testInsertSecondSignatureWithNumberOfElements(unsigned int countPushBacks){
	std::map<int, char> original;
	ft::map<int, char> fake;
	std::pair<int, char> pairSTD;
	ft::pair<int, char> pairFT;
	std::cout << WARNING << "TEST INSERT (iterator, value_type&) WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	for(unsigned int x = 1; x <= countPushBacks; ++x){
		pairSTD = std::make_pair(x, '!' + (x % 94));
		pairFT = ft::make_pair(x, '!' + (x % 94));
		original.insert(original.begin(), pairSTD);
		fake.insert(fake.begin(), pairFT);
	}
	if (!compareElementsMap(original, fake)) {
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

bool _testInsertThirdSignatureWithNumberOfElements(unsigned int countPushBacks){
	std::map<int, char> baseSTD;
	ft::map<int, char> baseFT;
	std::map<int, char> original;
	ft::map<int, char> fake;
	std::cout << WARNING << "TEST INSERT (iterator, iterator) WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, baseSTD, baseFT);
	original.insert(baseSTD.begin(), baseSTD.end());
	fake.insert(baseFT.begin(), baseFT.end());
	if (!compareElementsMap(original, fake)) {
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

void insertUnitTestsMap(t_resultTests &results){
	titleTest("INSERT TEST");
	_testInsertFirstSignatureWithNumberOfElements(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertFirstSignatureWithNumberOfElements(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;

	_testInsertSecondSignatureWithNumberOfElements(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertSecondSignatureWithNumberOfElements(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;

	_testInsertThirdSignatureWithNumberOfElements(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testInsertThirdSignatureWithNumberOfElements(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

double _benchmarkBaseInsertMap1(std::map<int, char> &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	std::pair<int, char> pair;
	unsigned int countElements = 10000;

	while(countElements){
		pair = std::make_pair(countElements, '!' + (countElements % 94));
		beforeClock = clock();
		map.insert(pair);
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

double _benchmarkBaseInsertMap1(ft::map<int, char> &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	ft::pair<int, char> pair;
	unsigned int countElements = 10000;

	while(countElements){
		pair = ft::make_pair(countElements, '!' + (countElements % 94));
		beforeClock = clock();
		map.insert(pair);
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

double insertBenchmarkMap1(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseInsertMap1(mapSTD, "STD");
	return _benchmarkBaseInsertMap1(mapFT, "FT");
}

double _benchmarkBaseInsertMap2(std::map<int, char> &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	std::pair<int, char> pair;
	unsigned int countElements = 10000;

	while(countElements){
		pair = std::make_pair(countElements, '!' + (countElements % 94));
		beforeClock = clock();
		map.insert(map.begin(), pair);
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


double _benchmarkBaseInsertMap2(ft::map<int, char> &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	ft::pair<int, char> pair;
	unsigned int countElements = 10000;

	while(countElements){
		pair = ft::make_pair(countElements, '!' + (countElements % 94));
		beforeClock = clock();
		map.insert(map.begin(), pair);
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

double insertBenchmarkMap2(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseInsertMap2(mapSTD, "STD");
	return _benchmarkBaseInsertMap2(mapFT, "FT");
}

double _benchmarkBaseInsertMap3(std::map<int, char> &map, std::string typeMap){
	double time = 0;
	std::map<int, char> base;
	std::map<int, char>::iterator itStart;
	std::map<int, char>::iterator itEnd;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 1000;

	while(countElements){
		base.insert(std::make_pair(countElements, '!' + (countElements % 94)));
		itStart = base.begin();
		itEnd = base.end();
		beforeClock = clock();
		map.insert(itStart, itEnd);
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

double _benchmarkBaseInsertMap3(ft::map<int, char> &map, std::string typeMap){
	double time = 0;
	ft::map<int, char> base;
	ft::map<int, char>::iterator itStart;
	ft::map<int, char>::iterator itEnd;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 1000;

	while(countElements){
		base.insert(ft::make_pair(countElements, '!' + (countElements % 94)));
		itStart = base.begin();
		itEnd = base.end();
		beforeClock = clock();
		map.insert(itStart, itEnd);
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

double insertBenchmarkMap3(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseInsertMap3(mapSTD, "STD");
	return _benchmarkBaseInsertMap3(mapFT, "FT");
}