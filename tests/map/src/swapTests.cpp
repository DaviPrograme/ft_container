/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:45:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _swapTestMap(unsigned int countPushBacks){
	std::map<int, char> original;
	std::map<int, char> tmpOriginal;
	ft::map<int, char> fake;
	ft::map<int, char> tmpFake;
	
	std::cout << WARNING << "SWAP TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, tmpOriginal, tmpFake);
	original.swap(tmpOriginal);
	fake.swap(tmpFake);
	if(original.size() != fake.size()){
		std::cout << KO << "(BASE)DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if(tmpOriginal.size() != tmpFake.size()){
		std::cout << KO << "(TMP)DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
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

void swapUnitTestsMap(t_resultTests &results){
	titleTest("SWAP TEST");
	_swapTestMap(1) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(2) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(3) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(4) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(5) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(6) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(7) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(8) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(9) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(100) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(500) ? results.countRightTests += 1 : results.countWrongTests += 1;
	_swapTestMap(1000) ? results.countRightTests += 1 : results.countWrongTests += 1;
}

template<class genericMap>
double _benchmarkBaseSwapMap(genericMap &map, std::string typeMap){
	genericMap tmp;
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	manyInsertElements(countElements, map);
	while(--countElements){	
		beforeClock = clock();
		map.swap(tmp);
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

double swapBenchmarkMap(std::string typeVector){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseSwapMap(mapSTD, "STD");
	return _benchmarkBaseSwapMap(mapFT, "FT");
}