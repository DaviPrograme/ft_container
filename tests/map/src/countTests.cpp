/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:43:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _countTestMap(unsigned int countPushBacks){
	std::map<int, char> original;
	ft::map<int, char> fake;
	
	std::cout << WARNING << "SWAP TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	for(unsigned int x = 0; x < countPushBacks + 10; ++x){
		if(original.count(x) != fake.count(x)){
			std::cout << KO << "DIVERGENCE BETWEEN RETURNS" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void countUnitTestsMap(t_resultTests &results){
	titleTest("COUNT TEST");
	_countTestMap(1) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(2) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(3) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(4) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(5) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(6) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(7) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(8) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(9) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(100) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(500) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_countTestMap(1000) ? results.countRightTests += 1 : results.countWrongTests += 1;
}

template<class genericMap>
double _benchmarkBaseCountMap(genericMap &map, std::string typeMap){
	genericMap tmp;
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	manyInsertElements(countElements, map);
	while(--countElements){	
		beforeClock = clock();
		map.count(countElements);
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

double countBenchmarkMap(std::string typeVector){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseCountMap(mapSTD, "STD");
	return _benchmarkBaseCountMap(mapFT, "FT");
}