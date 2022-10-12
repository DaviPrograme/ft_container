/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 21:50:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "containers/Vector.hpp"
#include "tests/vector/headers/vectorTests.hpp"
#include "tests/stack/headers/stackTests.hpp"
#include "tests/map/header/mapTests.hpp"

int main(int argc, char** argv)
{
	std::string selectedOption;
	if (argc != 2){
		std::cout << "\nERROR: use one of the commands [testsVector, ";
		std::cout << "benchmarkVector, testsMap, benchmarkMap, testsStack, "; 
		std::cout << "benchmarkStack]\n\n";
		return 1;	
	}
	selectedOption = argv[1];
	if (!selectedOption.compare("testsVector"))
		vectorUnitTests();
	else if (!selectedOption.compare("benchmarkVector"))
		vectorBenchmark();
	else if (!selectedOption.compare("testsMap"))
		mapUnitTests();
	else if (!selectedOption.compare("benchmarkMap"))
		mapBenchmark();
	else if (!selectedOption.compare("testsStack"))
		stackUnitTests();
	else if (!selectedOption.compare("benchmarkStack"))
		stackBenchmark();
	else {
		std::cout << "\nERROR: use one of the commands [testsVector, ";
		std::cout << "benchmarkVector, testsMap, benchmarkMap, testsStack, "; 
		std::cout << "benchmarkStack]\n\n";
		return 2;
	}
	return 0;
}