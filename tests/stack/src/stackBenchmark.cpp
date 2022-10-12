/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackBenchmark.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:46:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/stackTests.hpp"

void stackBenchmark(void){
	double accumulatedTimeSTD = 0;
	double accumulatedTimeFT = 0;
	int numberBenchmarkTests = 5;

	std::string titlesTest[] = {"constructor default", "top", "empty", "size", "push"};
	
	double(*benchmarkTests[])(std::string) = { constructorDefaultBenchmarkStack, \
	topBenchmarkStack, emptyBenchmarkStack, sizeBenchmarkStack, pushBenchmarkStack};

	for(int count = 0; count < numberBenchmarkTests; ++count){
		_subTitle(titlesTest[count]);
		_runBenchmarkTest(benchmarkTests[count], accumulatedTimeSTD, accumulatedTimeFT);
	}
	_showResultsBenchmarkTests(accumulatedTimeSTD, accumulatedTimeFT);
}