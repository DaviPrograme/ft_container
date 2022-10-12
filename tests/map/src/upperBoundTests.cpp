/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upperBoundTests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:12:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testUpperBoundWithNumberOfElementsMap(unsigned int countPushBacks){
	std::map<int,char> original;
	std::map<int,char>::iterator it;
	ft::map<int, char> fake;
	ft::map<int, char>::iterator fit;

	std::cout << WARNING << "UPPER_BOUND TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	manyInsertElements(countPushBacks, original, fake);
	for(unsigned int x = 1; x < countPushBacks - 1; ++x){
		it = original.upper_bound(x);
		fit = fake.upper_bound(x);
		if(it->first != fit->first) {
			std::cout << KO << "[1]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
			std::cout << "busca: " << x << "  original: " << it->first << "   fake: " << fit->first << "\n"; 
			return false;
		}
		if(it->second != fit->second) {
			std::cout << KO << "[1]DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	for(unsigned int x = 0; x < countPushBacks; ++x){
		if(x % 2 == 0){
			original.erase(x);
			fake.erase(x);
		}
	}
	for(unsigned int x = 1; x < countPushBacks - 2; ++x){
		if(original.size() < 2)
			break;
		it = original.upper_bound(x);
		fit = fake.upper_bound(x);
		if(it->first != fit->first) {
			std::cout << KO << "[2]DIVERGENCE BETWEEN KEY VALUES" << WHITE << "\n";
			return false;
		}
		if(it->second != fit->second) {
			std::cout << KO << "[2]DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void upperBoundUnitTestsMap(t_resultTests &results){
	titleTest("UPPER_BOUND TEST");
	_testUpperBoundWithNumberOfElementsMap(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testUpperBoundWithNumberOfElementsMap(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseUpperBoundMap(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	manyInsertElements(countElements, map);
	for(unsigned int index = 0; index < countElements;  ++index){
		beforeClock = clock();
		map.upper_bound(index);
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

double upperBoundBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int,char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseUpperBoundMap(mapSTD, "STD");
	return _benchmarkBaseUpperBoundMap(mapFT, "FT");
}