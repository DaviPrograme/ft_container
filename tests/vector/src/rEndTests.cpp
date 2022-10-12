/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rEndTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/08 03:25:21 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testRendWithNumberOfElementsInt(unsigned int countPushBacks){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int>::reverse_iterator itOriginal;
	ft::vector<int>::reverse_iterator itFake;
	
	std::cout << WARNING << "REND TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	for(size_t x = 1; x <= countPushBacks; ++x){
		original.push_back(x);
		fake.push_back(x);
	}
	itOriginal = original.rend();
	itFake = fake.rend();
	while(itOriginal != original.rbegin()){
		--itOriginal;
		--itFake;
		if (*itOriginal != *itFake) {
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
	}
	std::cout << OK << "\n";
	return true;
}

void rendUnitTests(t_resultTests &results){
	titleTest("REND TEST");
	_testRendWithNumberOfElementsInt(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testRendWithNumberOfElementsInt(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double _benchmarkBaseRend(genericVector vector, std::string typeVector){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 100000;

	while(--countElements){
		beforeClock = clock();
		vector.rend();
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

double rendBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;

	if(!typeVector.compare("STD"))
		return _benchmarkBaseRend(vectorSTD, "STD");
	return _benchmarkBaseRend(vectorFT, "FT");
}