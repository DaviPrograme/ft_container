/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eraseTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:20:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"


bool _testWithErase1(void){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int>::iterator itOriginal;
	ft::vector<int>::iterator itFake;
	
	std::cout << WARNING << "TEST 1 WITH ERASE(iterator position) - DELETE BEGINNING ELEMENT: " << WHITE;
	for(unsigned int index = 1; index < 10; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	itOriginal = original.erase(original.begin());
	itFake = fake.erase(fake.begin());
	if(*itOriginal != *itFake){
		std::cout << KO << "DIFFERENCE BETWEEN RETURNS" << WHITE << "\n";
		return false;
	}
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

bool _testWithErase2(void){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int>::iterator itOriginal;
	ft::vector<int>::iterator itFake;
	int countPushBacks = 4;
	
	std::cout << WARNING << "TEST 2 WITH ERASE(iterator position) - DELETE MIDDLE ELEMENT: " << WHITE;
	for(unsigned int index = 1; index < 10; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	itOriginal = original.erase( original.begin() + countPushBacks);
	itFake = fake.erase(fake.begin() + countPushBacks);
	if(*itOriginal != *itFake){
		std::cout << KO << "DIFFERENCE BETWEEN RETURNS" << WHITE << "\n";
		return false;
	}
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


bool _testWithErase3(void){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int>::iterator itOriginal;
	ft::vector<int>::iterator itFake;
	
	std::cout << WARNING << "TEST 3 WITH ERASE(iterator position) - DELETE END ELEMENT: " << WHITE;
	for(unsigned int index = 1; index < 10; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	itOriginal = original.erase( original.begin() + original.size() - 1);
	itFake = fake.erase(fake.begin() + fake.size() - 1);
	if(*itOriginal != *itFake){
		std::cout << KO << "DIFFERENCE BETWEEN RETURNS" << WHITE << "\n";
		return false;
	}
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

bool _testWithErase4(void){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int>::iterator itOriginal;
	ft::vector<int>::iterator itFake;
	int countPushBacks = 4;
	
	std::cout << WARNING << "TEST 4 WITH ERASE(iterator first, iterator last) - DELETE RANGE OF INITIAL ELEMENTS: " << WHITE;
	for(unsigned int index = 1; index < 10; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	itOriginal = original.erase(original.begin(), original.begin() + countPushBacks);
	itFake = fake.erase(fake.begin(), fake.begin() + countPushBacks);
	if(*itOriginal != *itFake){
		std::cout << KO << "DIFFERENCE BETWEEN RETURNS" << WHITE << "\n";
		return false;
	}
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

bool _testWithErase5(void){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int>::iterator itOriginal;
	ft::vector<int>::iterator itFake;
	int countPushBacks = 6;
	
	std::cout << WARNING << "TEST 5 WITH ERASE(iterator first, iterator last) - DELETE RANGE OF MIDDLE ELEMENTS: " << WHITE;
	for(unsigned int index = 1; index < 10; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	itOriginal = original.erase(original.begin() + 2, original.begin() + countPushBacks);
	itFake = fake.erase(fake.begin() + 2, fake.begin() + countPushBacks);
	if(*itOriginal != *itFake){
		std::cout << KO << "DIFFERENCE BETWEEN RETURNS" << WHITE << "\n";
		return false;
	}
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


bool _testWithErase6(void){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int>::iterator itOriginal;
	ft::vector<int>::iterator itFake;
	int countPushBacks = 4;
	
	std::cout << WARNING << "TEST 6 WITH ERASE(iterator first, iterator last) - DELETE RANGE OF END ELEMENTS: " << WHITE;
	for(unsigned int index = 1; index < 10; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	itOriginal = original.erase(original.begin() + 5, original.begin() + countPushBacks + 5);
	itFake = fake.erase(fake.begin() + 5, fake.begin() + countPushBacks + 5);
	if(*itOriginal != *itFake){
		std::cout << KO << "DIFFERENCE BETWEEN RETURNS" << WHITE << "\n";
		return false;
	}
	if(original.capacity() != fake.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;	
	}
	if (original.size() != fake.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if(!compareElementsVectors(original, fake)){
		std::cout << "ORIGINAL: ";
		while(itOriginal != original.end()){
			std::cout << *itOriginal << ", ";
			++itOriginal;
		}
		std::cout << " \n";
		std::cout << "FAKE: ";
		while(itFake != fake.end()){
			std::cout << *itFake << ", ";
			++itFake;
		}
		std::cout << " \n";
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}

void eraseUnitTests(t_resultTests &results){
	titleTest("ERASE TEST");
	_testWithErase1() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithErase2() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithErase3() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithErase4() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithErase5() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
	_testWithErase6() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
}

template<class genericVector>
double _benchmarkBaseErase1(genericVector vector, std::string typeVector){
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	
	manyPushBacksInts(countElements, vector);
	typename genericVector::iterator it;
	while(vector.size()){
		it = vector.begin();
		beforeClock = clock();
		vector.erase(it);
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

double eraseBenchmark1(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseErase1(vectorSTD, "STD");
	return _benchmarkBaseErase1(vectorFT, "FT");
}

template<class genericVector>
double _benchmarkBaseErase2(genericVector vector, std::string typeVector){
	unsigned int countElements = 2000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	manyPushBacksInts(countElements, vector);
	typename genericVector::iterator it;
	while(vector.size()){
		it = vector.begin();
		beforeClock = clock();
		vector.erase(it, it + 2);
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

double eraseBenchmark2(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseErase2(vectorSTD, "STD");
	return _benchmarkBaseErase2(vectorFT, "FT");
}