/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:17:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testAssignFirstSignature(unsigned int countPushBacks){
	std::vector<int> original;
	ft::vector<int> fake;
	int element = 42;
	 
	std::cout << WARNING << "ASSIGN (size_type, value_type) TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	original.assign(countPushBacks, element);
	fake.assign(countPushBacks, element);
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
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

bool _testAssignSecondSignature(unsigned int countPushBacks){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int> originalBase;
	ft::vector<int> fakeBase;
	 
	std::cout << WARNING << "ASSIGN (iterator, iterator) TEST WITH " << countPushBacks << " ELEMENT(S): " << WHITE;
	for(unsigned int x = 1; x <= countPushBacks ; ++x){
		originalBase.push_back(x);
		fakeBase.push_back(x);
	}
	original.assign(originalBase.begin(), originalBase.end());
	fake.assign(fakeBase.begin(), fakeBase.end());
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
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

void assignUnitTests(t_resultTests &results){
	titleTest("ASSIGN TEST");
	_testAssignFirstSignature(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignFirstSignature(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;

	_testAssignSecondSignature(1) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(2) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(3) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(4) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(5) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(6) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(7) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(8) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(9) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testAssignSecondSignature(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	std::cout << "\n";
}

template<class genericVector>
double _benchmmarkBaseAssign1(genericVector vector, std::string typeVector){
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	unsigned int sizeVector;

	while(vector.capacity() < countElements){
		sizeVector = vector.capacity() + 1;
		beforeClock = clock();
		vector.assign(sizeVector, 42);
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

double assignBenchmark1(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmmarkBaseAssign1(vectorSTD, "STD");
	return _benchmmarkBaseAssign1(vectorSTD, "FT");
}

template<class genericVector>
double _benchmarkBaseAssign2(genericVector vector, std::string typeVector){
	unsigned int countElements = 2000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	std::vector<int> vct;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	
	while(vector.capacity() < countElements){
		vct.push_back(42);
		it = vct.begin();
		ite = vct.end();
		beforeClock = clock();
		vector.assign(it, ite);
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

double assignBenchmark2(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseAssign2(vectorSTD, "STD");
	return _benchmarkBaseAssign2(vectorFT, "FT");
}