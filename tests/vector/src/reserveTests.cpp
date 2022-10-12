/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserveTests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/04 01:09:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testWithReserveLessVectorCapacity(void){
	std::vector<int> original;
	ft::vector<int> fake;
	unsigned int countPushBacks = 4;
	
	std::cout << WARNING << "TEST WITH RESERVE LESS THAN VECTOR CAPACITY: " << WHITE;
	manyPushBacksInts(countPushBacks, original);
	copyElementsVector(original, fake);
	original.reserve(1);
	fake.reserve(1);
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;	
	}
	if(!compareElementsVectors(original, fake)){
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

bool _testWithReserveEqualVectorCapacity(void){
	std::vector<int> original;
	ft::vector<int> fake;
	unsigned int countPushBacks = 4;
	
	std::cout << WARNING << "TEST WITH RESERVE EQUAL THAN VECTOR CAPACITY: " << WHITE;
	manyPushBacksInts(countPushBacks, original);
	copyElementsVector(original, fake);
	original.reserve(original.capacity());
	fake.reserve(fake.capacity());
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;
	}
	if(!compareElementsVectors(original, fake)){
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

bool _testWithReserveLargerVectorCapacity(void){
	std::vector<int> original;
	std::vector<int>::iterator it;
	ft::vector<int> fake;
	
	std::cout << WARNING << "TEST WITH RESERVE LARGER THAN VECTOR CAPACITY: " << WHITE;
	original.reserve(11);
	fake.reserve(11);
	while (original.capacity() < 100){
		if(original.capacity() != fake.capacity()){
			std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
			return false;
		}
		if(!compareElementsVectors(original, fake)){
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
		manyPushBacksInts(1, original);
		it = original.end();
		fake.push_back(*(--it));
	}
	std::cout << OK << "\n";
	return true;
}

bool _testWithReserveLargerMaxSize(void){
	ft::vector<int> fake;
	
	std::cout << WARNING << "TEST WITH RESERVE LARGER THAN MAX_SIZE(): " << WHITE;
	try{
		fake.reserve(fake.max_size() + 1);
	}catch(...){
		std::cout << OK << "\n";
		return true;	
	}
	std::cout << KO << "DIDN'T THROW EXCEPTION" << WHITE << "\n";
	return false;	
}

void reserveUnitTests(t_resultTests &results){
	titleTest("RESERVE TEST");
	_testWithReserveLessVectorCapacity() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithReserveEqualVectorCapacity() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithReserveLargerVectorCapacity() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithReserveLargerMaxSize() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
}

template<class genericVector>
double _benchmarkBaseReserve(genericVector vector, std::string typeVector){
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	size_t newCapacity;

	while(vector.capacity() < countElements){
		newCapacity = vector.capacity() + 1;
		beforeClock = clock();
		vector.reserve(newCapacity);
		afterClock = clock();
		accumulatedClock += afterClock - beforeClock;
	}
	time = (double)accumulatedClock / CLOCKS_PER_SEC;
	std::cout << WARNING << (!typeVector.compare("STD") ? "STD" : "FT");
	std::cout << ": " << GREEN; 
	std::cout <<  std::setprecision(TIME_PRECISION) << std::fixed << time;
	std::cout << "\n" << WHITE ; 
	return time;
}

double reserveBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseReserve(vectorSTD, "STD");
	return _benchmarkBaseReserve(vectorFT, "FT");
}