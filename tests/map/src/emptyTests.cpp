/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emptyTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:19:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _testEmptyWithoutElements(void){
	std::map<int, char> original;
	ft::map<int, char> fake;
	
	std::cout << WARNING << "EMPTY TEST WITHOUT ELEMENTS: " << WHITE;
	if (original.empty() != fake.empty()){
		std::cout << KO << "DIFFERENCE BETWEEN EMPTY" << "\n";
		return false;	
	}
	std::cout << OK << "\n";
	return true;
}

bool _testEmptyWithElements(void){
	std::map<int, char> original;
	ft::map<int, char> fake;
	
	std::cout << WARNING << "EMPTY TEST WITH ELEMENTS: " << WHITE;
	manyInsertElements(10, original, fake);
	if (original.empty() != fake.empty()){
		std::cout << KO << "DIFFERENCE BETWEEN EMPTY" << "\n";
		return false;	
	}
	std::cout << OK << "\n";
	return true;
}

void emptyUnitTestsMap(t_resultTests &results){
	titleTest("EMPTY TEST");
	_testEmptyWithoutElements() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testEmptyWithElements() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericMap>
double _benchmarkBaseEmpty(genericMap &map, std::string typeMap){
	unsigned int countElements = 100000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(--countElements){
		beforeClock = clock();
		map.empty();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << (!typeMap.compare("STD") ? "STD" : "FT");
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double emptyBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;
	
	if (!typeMap.compare("STD"))
		return _benchmarkBaseEmpty(mapSTD, "STD");
	return _benchmarkBaseEmpty(mapFT, "FT");
}