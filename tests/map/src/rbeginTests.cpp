/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbeginTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:11:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testRbeginWithNumberOfElementsMap(unsigned int countPushBacks){
	std::map<int, char> original;
	ft::map<int, char> fake;
	std::map<int, char>::reverse_iterator itOriginal;
	ft::map<int, char>::reverse_iterator itFake;
	
	std::cout << WARNING << "RBEGIN TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	itOriginal = original.rbegin();
	itFake = fake.rbegin();
	while(itOriginal != original.rend()){
		if (itFake == fake.rend()) {
			std::cout << KO << "FT HAS LESS ELEMENTS THAN STD" << WHITE << "\n";
			return false;
		}
		if ((itOriginal->first != itFake->first) || (itOriginal->second != itFake->second)) {
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
		++itOriginal;
		++itFake;
	}
	std::cout << OK << "\n";
	return true;
}

void rbeginUnitTestsMap(t_resultTests &results){
	titleTest("RBEGIN TEST");
	_testRbeginWithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRbeginWithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseRbegin(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	manyInsertElements(1, map);
	while(--countElements){
		beforeClock = clock();
		map.rbegin();
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

double rbeginBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseRbegin(mapSTD, "STD");
	return _benchmarkBaseRbegin(mapFT, "FT");
}