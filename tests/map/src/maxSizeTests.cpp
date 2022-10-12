/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSizeTests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/08 01:02:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool _maxSizeTestMap(void){
	std::map<int, char> original;
	ft::map<int, char> fake;
	
	std::cout << WARNING << "MAX_SIZE TEST: " << WHITE;
	if(!fake.max_size()){
		std::cout << KO << "NO RETURN FROM MAX_SIZE" << WHITE << "\n";
		return false;	
	}
	std::cout << OK << "\n";
	return true;
}

void maxSizeUnitTestsMap(t_resultTests &results){
	titleTest("MAX_SIZE TEST");
	_maxSizeTestMap() ? results.countRightTests += 1 : results.countWrongTests += 1;
}

template<class genericMap>
double _benchmarkBaseMaxSizeMap(genericMap &map, std::string typeMap){
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(--countElements){
		beforeClock = clock();
		map.max_size();
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

double maxSizeBenchmarkMap(std::string typeMap){
	std::map<int, char> mapSTD;
	ft::map<int, char> mapFT;
	
	if (!typeMap.compare("STD"))
		return _benchmarkBaseMaxSizeMap(mapSTD, "STD");
	return _benchmarkBaseMaxSizeMap(mapFT, "FT");
}