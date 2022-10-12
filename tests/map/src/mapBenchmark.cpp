/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapBenchmark.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:44:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/mapTests.hpp"

void mapBenchmark(void){
	double accumulatedTimeSTD = 0;
	double accumulatedTimeFT = 0;
	int numberBenchmarkTests = 28;

	std::string titlesTest[] = {"insert - (value_type&)", \
	"insert - (iterator, value_type&)", "insert - (iterator, iterator)", "size", "begin", "end", \
	"rbegin" , "rend", "empty", "max_size", "at", "operator[]", "clear", "erase - (iterator)", \
	"erase - (key_type)", "erase - (iterator, iterator)", "swap", "count", "find", "lower_bound", \
	"upper_bound", "equal_range", "value_comp", "key_comp", "get_allocator", "constructor default", \
	"constructor copy", "constructor range"};
	
	double(*benchmarkTests[])(std::string) = { insertBenchmarkMap1, insertBenchmarkMap2, \
	insertBenchmarkMap3, sizeBenchmarkMap, beginBenchmarkMap, endBenchmarkMap, rbeginBenchmarkMap, \
	rendBenchmarkMap, emptyBenchmarkMap, maxSizeBenchmarkMap, atBenchmarkMap, operatorArrayBenchmarkMap, \
	clearBenchmarkMap, erase1BenchmarkMap, erase2BenchmarkMap, erase3BenchmarkMap, swapBenchmarkMap, \
	countBenchmarkMap, findBenchmarkMap, lowerBoundBenchmarkMap, upperBoundBenchmarkMap, \
	equalRangeBenchmarkMap, valueCompBenchmarkMap, keyCompBenchmarkMap, getAllocatorBenchmarkMap,\
	constructorDefaultBenchmarkMap, constructorCopyBenchmarkMap, constructorRangeBenchmarkMap};

	for(int count = 0; count < numberBenchmarkTests; ++count){
		_subTitle(titlesTest[count]);
		_runBenchmarkTest(benchmarkTests[count], accumulatedTimeSTD, accumulatedTimeFT);
	}
	_showResultsBenchmarkTests(accumulatedTimeSTD, accumulatedTimeFT);
}