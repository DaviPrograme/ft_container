/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorBenchmark.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/11 10:47:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/vectorTests.hpp"

void vectorBenchmark(void){
	double accumulatedTimeSTD = 0;
	double accumulatedTimeFT = 0;
	int numberBenchmarkTests = 28;

	std::string titlesTest[] = { "size", "capacity", "empty", "max_size", \
		"push_back", "pop_back", "reserve", "clear", "resize", "swap", \
		"erase - (iterator)", "erase - (iterator, iterator)", \
		"insert - (iterator, value_type)", "insert - (iterator, size_type, value_type)", \
		"insert - (iterator, iterator, iterator)", "assign - (size_type, value_type)", \
		"assign - (iterator, iterator)", "at", "back", "front", "begin", "end", "rbegin", \
		"rend", "data", "constructor default", "constructor fill", "constructor range"};
	
	double(*benchmarkTests[])(std::string) = { sizeBenchmark, capacityBenchmark,\
		emptyBenchmark, maxSizeBenchmark, pushBackBenchmark, popBackBenchmark, \
		reserveBenchmark, clearBenchmark, resizeBenchmark, swapBenchmark, eraseBenchmark1, \
		eraseBenchmark2, insertBenchmark1, insertBenchmark2, insertBenchmark3, \
		assignBenchmark1, assignBenchmark2, atBenchmark, backBenchmark, frontBenchmark, \
		beginBenchmark, endBenchmark, rbeginBenchmark, rendBenchmark, dataBenchmark,\
		constructorDefaultBenchmark, constructorFillBenchmark, constructorRangeBenchmark};

	for(int count = 0; count < numberBenchmarkTests; ++count){
		_subTitle(titlesTest[count]);
		_runBenchmarkTest(benchmarkTests[count], accumulatedTimeSTD, accumulatedTimeFT);
	}
	_showResultsBenchmarkTests(accumulatedTimeSTD, accumulatedTimeFT);
}