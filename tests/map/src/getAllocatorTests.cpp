/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getAllocatorTests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/06 04:09:47 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testGetAllocatorWithNumberOfElements(unsigned int countPushBacks){
	ft::map<int, char> fake;
	ft::map<int, char>::value_type *ptrFake =  NULL;

	std::cout << WARNING << "GET_ALLOCATOR TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	for(unsigned int x = 0; x < countPushBacks; ++x){
		ptrFake = fake.get_allocator().allocate(1);
		if(!ptrFake){
			std::cout << KO << "ALLOCATION ERROR" << WHITE << "\n";
			return false;
		}
		fake.get_allocator().deallocate(ptrFake, 1);
		ptrFake = NULL;
	}
	std::cout << OK << "\n";
	return true;
}

void getAllocatorUnitTestsMap(t_resultTests &results){
	titleTest("GET_ALLOCATOR TEST");
	_testGetAllocatorWithNumberOfElements(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testGetAllocatorWithNumberOfElements(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseGetAllocatorMap(genericMap &map, std::string typeMap){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	manyInsertElements(countElements, map);
	while(countElements){
		beforeClock = clock();
		map.get_allocator();
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

double getAllocatorBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;

	if(!typeMap.compare("STD"))
		return _benchmarkBaseGetAllocatorMap(mapSTD, "STD");
	return _benchmarkBaseGetAllocatorMap(mapFT, "FT");
}
