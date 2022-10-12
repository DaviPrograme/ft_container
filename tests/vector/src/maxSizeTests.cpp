/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSizeTests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:22:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _maxSizeTest(void){
	std::vector<int> original;
	ft::vector<int> fake;
	
	std::cout << WARNING << "MAX_SIZE TEST: " << WHITE;
	if(original.max_size() != fake.max_size()){
		std::cout << KO << "DIFFERENCE BETWEEN MAX SIZES" << WHITE << "\n";
		return false;	
	}
	std::cout << OK << "\n";
	return true;
}

void maxSizeUnitTests(t_resultTests &results){
	titleTest("MAX_SIZE TEST");
	_maxSizeTest() ? results.countRightTests += 1 : results.countWrongTests += 1;
}

template<class genericVector>
double _benchmarkBaseMaxSize(genericVector vector, std::string typeVector){
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(--countElements){
		beforeClock = clock();
		vector.max_size();
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeVector;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double maxSizeBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseMaxSize(vectorSTD, "STD");
	return _benchmarkBaseMaxSize(vectorFT, "FT");
}