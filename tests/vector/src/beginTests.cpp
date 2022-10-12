/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/08 00:30:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testBeginWithNumberOfElementsInt(unsigned int countPushBacks){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int>::iterator itOriginal;
	ft::vector<int>::iterator itFake;
	
	std::cout << WARNING << "BEGIN TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	for(size_t x = 1; x <= countPushBacks; ++x){
		original.push_back(x);
		fake.push_back(x);
	}
	itOriginal = original.begin();
	itFake = fake.begin();
	while(itOriginal != original.end()){
		if (itFake == fake.end()) {
			std::cout << KO << "FT HAS LESS ELEMENTS THAN STD" << WHITE << "\n";
			return false;
		}
		if (*itOriginal != *itFake) {
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
		++itOriginal;
		++itFake;
	}
	std::cout << OK << "\n";
	return true;
}

void beginUnitTests(t_resultTests &results){
	titleTest("BEGIN TEST");
	_testBeginWithNumberOfElementsInt(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testBeginWithNumberOfElementsInt(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double _benchmarkBaseBegin(genericVector vector, std::string typeVector){
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 100000;

	while(--countElements){
		beforeClock = clock();
		vector.begin();
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

double beginBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;

	if(!typeVector.compare("STD"))
		return _benchmarkBaseBegin(vectorSTD, "STD");
	return _benchmarkBaseBegin(vectorFT, "FT");
}