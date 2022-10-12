/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyCompTests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:10:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testKeyCompWithNumberOfElementsMap(unsigned int b){
	std::map<int,char> original;
	ft::map<int, char> fake;

	std::cout << WARNING << "KEY_COMP TEST WITH " << b << " ELEMENT(S): " << WHITE;
	for(unsigned int a = 0; a <= b; ++a, --b){
		if(original.key_comp()(a, b) != fake.key_comp()(a, b)) {
			std::cout << KO << "[A-B]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
			return false;
		}
		if(original.key_comp()(b, a) != fake.key_comp()(b, a)) {
			std::cout << KO << "[B-A]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
			return false;
		}
		if(original.key_comp()(a, a) != fake.key_comp()(a, a)) {
			std::cout << KO << "[A-A]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void KeyCompUnitTestsMap(t_resultTests &results){
	titleTest("KEY_COMP TEST");
	_testKeyCompWithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testKeyCompWithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseKeyCompMap(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	for(unsigned int index = 0; index < countElements;  ++index){
		beforeClock = clock();
		map.key_comp()(index, countElements);
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

double keyCompBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int,char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseKeyCompMap(mapSTD, "STD");
	return _benchmarkBaseKeyCompMap(mapFT, "FT");
}