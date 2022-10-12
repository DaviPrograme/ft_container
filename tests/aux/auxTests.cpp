/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/06/07 05:51:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./auxTests.hpp"
#include <math.h>
#include <algorithm>
#include <iomanip>
#define STD "STD"
#define FT "FT"

std::string titleTest(std::string str){
	unsigned int defaultLenghtLine = 50;
	int lenghtLine = str.size() > defaultLenghtLine ? str.size() : defaultLenghtLine;
	int count = 0;
	std::string line;
	std::cout << TITLE;
	while(++count <= lenghtLine)
		line += "_";
	std::cout << line << "\n";
	count = (lenghtLine - str.size())/2;
	while(--count >= 0)
		std::cout << " ";
	std::cout << str << "\n";
	count = 0;
	std::cout << line << "\n\n" << WHITE;
	return line + "\n\n";
}


//benchmark tests
void _compareSpeedBetween(double timeSTD, double timeFT){
	double percentageComparison = (timeSTD - timeFT) / timeSTD;
	std::string answer = percentageComparison < 0 ? "Slower" : "Faster";
	std::string color = percentageComparison < 0 ? KO : GREEN;
	std::cout << WARNING << "Result: " << color;
	std::cout << std::fabs(percentageComparison) << " times ";
	std::cout << answer << "\n\n" << WHITE;
}

void _runBenchmarkTest(double (*benchmarkTest)(std::string type), double &accumulatedSTD, double &accumulatedFT){
	double timeSTD;
	double timeFT;

	timeSTD = benchmarkTest(STD);
	timeFT = benchmarkTest(FT);
	accumulatedSTD += timeSTD;
	accumulatedFT += timeFT;
	_compareSpeedBetween(timeSTD, timeFT);
}

void _subTitle(std::string subTitle){
	int maxSubtitleSize = 40;
	int count = (maxSubtitleSize - subTitle.size()) / 2;
	std::string titlePrefix;

	for (int x = 0; x <= count; x += 2)
		titlePrefix += "~-";
	std::cout << WARNING << titlePrefix << subTitle;
	reverse(titlePrefix.begin(), titlePrefix.end());
	std::cout << titlePrefix << "\n" << WHITE; 
}

void _showResultsBenchmarkTests(double &timeSTD, double &timeFT){
	unsigned int defaultLenghtLine = 65;
	std::cout << WARNING;
	while(--defaultLenghtLine)	
		std::cout << "_";
	std::cout << GREEN << "\ntime STD: " << timeSTD;
	std::cout << "    ";
	std::cout << KO << "time FT: " << timeFT;
	std::cout << "    ";
	_compareSpeedBetween(timeSTD, timeFT);
	std::cout << WHITE;
}



// unit tests
void showResults(t_resultTests &results){
	unsigned int defaultLenghtLine = 60;
	std::cout << TITLE;
	while(--defaultLenghtLine)	
		std::cout << "_";
	std::cout << GREEN << "\napproved tests: " << results.countRightTests;
	std::cout << "    ";
	std::cout << KO << "fail tests: " << results.countWrongTests;
	std::cout << "    ";
	double passRate = (results.countRightTests / 
					(double)(results.countRightTests +  results.countWrongTests)) * 100;
	std::cout << GREEN << "pass rate: " << std::setprecision(2) << std::fixed << passRate << "%\n\n";
	std::cout << WHITE;
}

void _showTitle(std::string title){
	int maxSubtitleSize = 50;
	int count = ((maxSubtitleSize / 2) - (title.size() / 2));
	std::string titlePrefix;

	for (int x = 0; x <= count; x += 2)
		titlePrefix += "#=";
	std::cout << TITLE << titlePrefix << title;
	reverse(titlePrefix.begin(), titlePrefix.end());
	std::cout << titlePrefix << "\n\n" << WHITE; 
}

void _initializeResultTests(t_resultTests &results){
	results.countRightTests = 0;
	results.countWrongTests = 0;
}