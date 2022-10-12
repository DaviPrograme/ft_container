/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructorFillTests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/10 15:18:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testConstructorFillVector(size_t countElements){
	std::vector<int> original(countElements, 42);
	ft::vector<int> fake(countElements, 42);
	std::cout << WARNING << "CONSTRUCTOR FILL WITH " << countElements << " ELEMENT(S): " << WHITE;
	if (original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << "\n";
		return false;	
	}
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if (!compareElementsVectors(original, fake)) {
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

void constructorFillUnitTests(t_resultTests &results){
	titleTest("CONSTRUCTOR FILL TEST");
	_testConstructorFillVector(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testConstructorFillVector(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double baseLoopConstructorFill(genericVector &vector){
	clock_t beforeClock;
	clock_t afterClock;

	beforeClock = clock();
	genericVector vectorTeste(1000, 42);
	afterClock = clock();
	vector.size();
	return afterClock - beforeClock;
}

template<class genericVector>
double _benchmarkConstructorFill(genericVector &vector, std::string typeVector){
	double time = 0;
	clock_t accumulatedClock = 0;
	unsigned int countElements = 10000;

	while(--countElements)
		accumulatedClock += baseLoopConstructorFill(vector);
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << typeVector;
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double constructorFillBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;

	if(!typeVector.compare("STD"))
		return _benchmarkConstructorFill(vectorSTD, "STD");
	return _benchmarkConstructorFill(vectorFT, "FT");
}