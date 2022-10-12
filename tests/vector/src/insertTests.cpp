/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/03 21:30:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testWithInsertFirstSignature(unsigned int &numTest, std::string position, bool isSizeEqualCapacity){
	std::vector<int> original;
	ft::vector<int> fake;
	int elementInserted = 42;
	unsigned int limitElements;
	std::string strLocalization;
	std::string strSizeAndCapacity;
	std::vector<int>::iterator itOriginalReturn;
	ft::vector<int>::iterator itFakeReturn;
	std::vector<int>::iterator itOriginalInsert;
	ft::vector<int>::iterator itFakeInsert;
	
	if(isSizeEqualCapacity){
		strSizeAndCapacity = "size == capacity: ";
		limitElements = 8;
	}else{
		strSizeAndCapacity = "size < capacity: ";
		limitElements = 7;
	}
	for(unsigned int index = 1; index <= limitElements; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	if(!position.compare("start")){
		itOriginalInsert = original.begin();
		itFakeInsert = fake.begin();
		strLocalization = " AT START ";
	}
	else if (!position.compare("middle")){
		itOriginalInsert = original.begin() + (limitElements / 2);
		itFakeInsert = fake.begin() + (limitElements / 2);
		strLocalization = " IN THE MIDDLE ";
	}
	else{
		itOriginalInsert = original.end();
		itFakeInsert = fake.end();
		strLocalization = " AT THE END ";
	}
	numTest += 1;
	std::cout << WARNING << "TEST " << numTest << " WITH INSERT(iterator, value_type) - INSERT ELEMENT" << strLocalization << "- "<< strSizeAndCapacity << WHITE;
	itOriginalReturn = original.insert(itOriginalInsert, elementInserted);
	itFakeReturn = fake.insert(itFakeInsert, elementInserted);
	if(*itOriginalReturn != *itFakeReturn){
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

bool _testWithInsertSecondSignature(unsigned int &numTest, std::string position, bool isSizeEqualCapacity){
	std::vector<int> original;
	ft::vector<int> fake;
	int elementInserted = 42;
	unsigned int countInserts = 5;
	unsigned int limitElements;
	std::string strLocalization;
	std::string strSizeAndCapacity;
	std::vector<int>::iterator itOriginalInsert;
	ft::vector<int>::iterator itFakeInsert;
	
	if(isSizeEqualCapacity){
		strSizeAndCapacity = "size == capacity: ";
		limitElements = 32;
	}else{
		strSizeAndCapacity = "size < capacity: ";
		limitElements = 32 - countInserts;
	}
	for(unsigned int index = 1; index <= limitElements; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	if(!position.compare("start")){
		itOriginalInsert = original.begin();
		itFakeInsert = fake.begin();
		strLocalization = " AT START ";
	}
	else if (!position.compare("middle")){
		itOriginalInsert = original.begin() + (limitElements / 2);
		itFakeInsert = fake.begin() + (limitElements / 2);
		strLocalization = " IN THE MIDDLE ";
	}
	else{
		itOriginalInsert = original.end();
		itFakeInsert = fake.end();
		strLocalization = " AT THE END ";
	}
	numTest += 1;
	std::cout << WARNING << "TEST " << numTest << " WITH INSERT(iterator, size_type, value_type) - INSERT ELEMENT" << strLocalization << "- "<< strSizeAndCapacity << WHITE;
	original.insert(itOriginalInsert, countInserts, elementInserted);
	fake.insert(itFakeInsert, countInserts, elementInserted);
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


bool _testWithInsertThirdSignature(unsigned int &numTest, std::string position, bool isSizeEqualCapacity){
	std::vector<int> original;
	ft::vector<int> fake;
	std::vector<int> originalBase;
	ft::vector<int> fakeBase;
	unsigned int countInserts = 5;
	unsigned int limitElements;
	std::string strLocalization;
	std::string strSizeAndCapacity;
	std::vector<int>::iterator itOriginalInsert;
	ft::vector<int>::iterator itFakeInsert;
	
	if(isSizeEqualCapacity){
		strSizeAndCapacity = "size == capacity: ";
		limitElements = 32;
	}else{
		strSizeAndCapacity = "size < capacity: ";
		limitElements = 32 - countInserts;
	}
	for(unsigned int index = 1; index <= limitElements; ++index){
		original.push_back(index);
		fake.push_back(index);
	}
	for(unsigned int index = 1; index <= countInserts; ++index){
		originalBase.push_back(index * 100);
		fakeBase.push_back(index * 100);
	}
	if(!position.compare("start")){
		itOriginalInsert = original.begin();
		itFakeInsert = fake.begin();
		strLocalization = " AT START ";
	}
	else if (!position.compare("middle")){
		itOriginalInsert = original.begin() + (limitElements / 2);
		itFakeInsert = fake.begin() + (limitElements / 2);
		strLocalization = " IN THE MIDDLE ";
	}
	else{
		itOriginalInsert = original.end();
		itFakeInsert = fake.end();
		strLocalization = " AT THE END ";
	}
	numTest += 1;
	std::cout << WARNING << "TEST " << numTest << " WITH INSERT(iterator, iterator, iterator) - INSERT ELEMENT" << strLocalization << "- "<< strSizeAndCapacity << WHITE;
	original.insert(itOriginalInsert, originalBase.begin(), originalBase.end());
	fake.insert(itFakeInsert, fakeBase.begin(), fakeBase.end());
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


void insertUnitTests(t_resultTests &results){
	titleTest("INSERT TEST");
	unsigned int countTests = 0;
	_testWithInsertFirstSignature(countTests, "start", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertFirstSignature(countTests, "middle", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertFirstSignature(countTests, "end", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertFirstSignature(countTests, "start", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertFirstSignature(countTests, "middle", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertFirstSignature(countTests, "end", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	
	_testWithInsertSecondSignature(countTests, "start", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertSecondSignature(countTests, "middle", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertSecondSignature(countTests, "end", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertSecondSignature(countTests, "start", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertSecondSignature(countTests, "middle", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertSecondSignature(countTests, "end", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;

	_testWithInsertThirdSignature(countTests, "start", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertThirdSignature(countTests, "middle", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertThirdSignature(countTests, "end", false) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertThirdSignature(countTests, "start", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertThirdSignature(countTests, "middle", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
	_testWithInsertThirdSignature(countTests, "end", true) ? \
		results.countRightTests += 1 : results.countWrongTests += 1;
}

template<class genericVector>
double _benchmarkBaseInsert1(genericVector vector, std::string typeVector){
	unsigned int countElements = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	typename genericVector::iterator it;
	while(vector.size() < countElements){
		it = vector.begin();
		beforeClock = clock();
		vector.insert(it, 42);
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

double insertBenchmark1(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseInsert1(vectorSTD, "STD");	
	return _benchmarkBaseInsert1(vectorFT, "FT");
}

template<class genericVector>
double _benchmarkBaseInsert2(genericVector vector, std::string typeVector){
	unsigned int countElements = 2000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	typename genericVector::iterator it;
	while(vector.size() < countElements){
		it = vector.begin();
		beforeClock = clock();
		vector.insert(it, 2, 42);
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

double insertBenchmark2(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseInsert2(vectorSTD, "STD");
	return _benchmarkBaseInsert2(vectorFT, "FT");
}

template<class genericVector>
double _benchmarkBase3(genericVector vector, std::string typeVector){
	unsigned int countElements = 2000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;

	typename genericVector::iterator it;
	genericVector vectorAux;
	vectorAux.push_back(42);
	vectorAux.push_back(43);
	typename genericVector::iterator first = vectorAux.begin();
	typename genericVector::iterator last = vectorAux.end();
	while(vector.size() < countElements){
		it = vector.begin();
		beforeClock = clock();
		vector.insert(it, first, last);
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


double insertBenchmark3(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBase3(vectorSTD, "STD");
	return _benchmarkBase3(vectorFT, "FT");
}