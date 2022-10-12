/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizeTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/04 00:24:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testWithResizeLessVectorCapacity(void){
	std::vector<int> original;
	ft::vector<int> fake;
	unsigned int numResize = 5;
	unsigned int countPushBacks = 30;
	
	std::cout << WARNING << "TEST WITH RESIZE LESS THAN VECTOR CAPACITY: " << WHITE;
	manyPushBacksInts(countPushBacks, original);
	copyElementsVector(original, fake);
	original.resize(numResize);
	fake.resize(numResize);
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;	
	}
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if(!compareElementsVectors(original, fake)){
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

bool _testWithResizeEqualVectorCapacity(void){
	std::vector<int> original;
	ft::vector<int> fake;
	unsigned int numResize = 30;
	unsigned int countPushBacks = 30;
	
	std::cout << WARNING << "TEST WITH RESIZE EQUAL THAN VECTOR CAPACITY: " << WHITE;
	manyPushBacksInts(countPushBacks, original);
	copyElementsVector(original, fake);
	original.resize(numResize);
	fake.resize(numResize);
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;	
	}
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if(!compareElementsVectors(original, fake)){
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

bool _testWithResizeLargerVectorCapacity(void){
	std::vector<int> original;
	ft::vector<int> fake;
	unsigned int countPushBacks = 30;
	
	std::cout << WARNING << "TEST WITH RESIZE LARGER THAN VECTOR CAPACITY: " << WHITE;
	manyPushBacksInts(countPushBacks, original);
	copyElementsVector(original, fake);
	original.resize(original.capacity() + 1, 42);
	fake.resize(fake.capacity() + 1, 42);
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;	
	}
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if(!compareElementsVectors(original, fake)){
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}


bool _testWithResizeBeingTreeTimesVectorCapacity(void){
	std::vector<int> original;
	ft::vector<int> fake;
	unsigned int countPushBacks = 30;
	
	std::cout << WARNING << "TEST WITH RESIZE BEING THREE TIMES THE VECTOR CAPACITY: " << WHITE;
	manyPushBacksInts(countPushBacks, original);
	copyElementsVector(original, fake);
	original.resize((original.capacity() * 3) + 1, 42);
	fake.resize((fake.capacity() * 3) + 1, 42);
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;	
	}
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if(!compareElementsVectors(original, fake)){
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

bool _testWithResizeUntilReachingLimitCapacity(size_t limitCapacity){
	std::vector<int> original;
	ft::vector<int> fake;
	
	std::cout << WARNING << "TEST WITH RESIZE UNTIL IT REACHES THE CAPACITY OF ";
	std::cout << limitCapacity << " ELEMENTS: " << WHITE;
	while(original.capacity() <= limitCapacity){
		if(original.capacity() != fake.capacity()){
			std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
			return false;	
		}
		if (original.size() != fake.size()){
			std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
			return false;	
		}
		if(!compareElementsVectors(original, fake)){
			std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
			return false;
		}
		original.resize(original.capacity() + 1, original.capacity());
		fake.resize(fake.capacity() + 1, fake.capacity());
	}
	std::cout << OK << "\n";
	return true;
}


void resizeUnitTests(t_resultTests &results){
	titleTest("RESIZE TEST");
	_testWithResizeLessVectorCapacity() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithResizeEqualVectorCapacity() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithResizeLargerVectorCapacity() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithResizeBeingTreeTimesVectorCapacity() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithResizeUntilReachingLimitCapacity(50) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithResizeUntilReachingLimitCapacity(100) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithResizeUntilReachingLimitCapacity(500) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithResizeUntilReachingLimitCapacity(1000) ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
}

template<class genericVector>
double _benchmarkBaseResize(genericVector vector, std::string typeVector){
	unsigned int countElements = 1000;
	double time = 0;
	size_t newCapacity;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	while(vector.capacity() < countElements){
		newCapacity = vector.capacity() + 1;
		beforeClock = clock();
		vector.resize(newCapacity, 42);
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

double resizeBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseResize(vectorSTD, "STD");
	return _benchmarkBaseResize(vectorFT, "FT");
}