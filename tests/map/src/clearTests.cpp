/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:06:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _clearTestMap(unsigned int countPushBacks){
	std::map<int, char> original;
	ft::map<int, char> fake;
	
	std::cout << WARNING << "CLEAR TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	original.clear();
	fake.clear();
	
	if(original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	std::cout << OK << "\n";
	return true;
}

void clearUnitTestsMap(t_resultTests &results){
	titleTest("CLEAR TEST");
	_clearTestMap(1) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(2) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(3) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(4) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(5) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(6) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(7) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(8) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(9) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(100) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(500) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_clearTestMap(1000) ? results.countRightTests += 1 : results.countWrongTests += 1;
}

template<class genericMap>
double _benchmarkBaseClearMap(genericMap &map, std::string typeMap){
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(--countElements){
		manyInsertElements(10, map);
		beforeClock = clock();
		map.clear();
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

double clearBenchmarkMap(std::string typeVector){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseClearMap(mapSTD, "STD");
	return _benchmarkBaseClearMap(mapFT, "FT");
}