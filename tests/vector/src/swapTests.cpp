/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/04 00:54:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

bool _testWithSwapVectorsSameType(void){
	ft::vector<int> src;
	ft::vector<int> dst;
	ft::vector<int> copy;
	unsigned int countPushBacks = 30;
	
	std::cout << WARNING << "SWAP TEST WITH VECTORS OF THE SAME TYPE: " << WHITE;
	manyPushBacksInts(countPushBacks, src);
	copyElementsVector(src, copy);
	unsigned int capacitySRC = src.capacity();
	src.swap(dst);
	if(dst.capacity() != capacitySRC || src.capacity()){
		std::cout << KO << "DIFFERENCE BETWEEN CAPACITY" << WHITE << "\n";
		return false;	
	}
	if (dst.size() != countPushBacks || src.size()){
		std::cout << KO << "DIFFERENCE BETWEEN SIZES" << WHITE << "\n";
		return false;	
	}
	if(!compareElementsVectors(dst, copy)){
		std::cout << KO << "DIVERGENCE BETWEEN STORED VALUES" << WHITE << "\n";
		return false;
	}
	std::cout << OK << "\n";
	return true;
}


void swapUnitTests(t_resultTests &results){
	titleTest("SWAP TEST");
	_testWithSwapVectorsSameType() ? results.countRightTests += 1 \
		: results.countWrongTests += 1;
}

template<class genericVector>
double _benchmarkBaseSwap(genericVector vector, std::string typeVector){
	unsigned int countPushBacks = 30;
	unsigned int count = 1000;
	double time = 0;
	clock_t beforeClock;
	clock_t afterClock;
	clock_t accumulatedClock = 0;
	genericVector src;

	manyPushBacksInts(countPushBacks, src);
	while(--count){
		beforeClock = clock();
		vector.swap(src);
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

double swapBenchmark(std::string typeVector){
	std::vector<int> vectorSTD;
	ft::vector<int> vectorFT;
	
	if (!typeVector.compare("STD"))
		return _benchmarkBaseSwap(vectorSTD, "STD");
	return _benchmarkBaseSwap(vectorFT, "FT");
}