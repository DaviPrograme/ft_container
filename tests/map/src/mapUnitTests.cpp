/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapUnitTests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:44:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"


void mapUnitTests(void){
	t_resultTests results;
	unsigned int numberUnitTests = 24;
	void(*unitTests[])(t_resultTests &results) = {insertUnitTestsMap, sizeUnitTestsMap, \
		beginUnitTestsMap, endUnitTestsMap, rbeginUnitTestsMap, rendUnitTestsMap, emptyUnitTestsMap,\
		maxSizeUnitTestsMap, atUnitTestsMap, operatorArrayUnitTestsMap, clearUnitTestsMap, \
		eraseUnitTestsMap, swapUnitTestsMap, countUnitTestsMap, findUnitTestsMap, \
		lowerBoundUnitTestsMap, upperBoundUnitTestsMap, equalRangeUnitTestsMap, valueCompUnitTestsMap, 
		KeyCompUnitTestsMap, getAllocatorUnitTestsMap, constructorDefaultUnitTestsMap, constructorCopyUnitTestsMap, \
		constructorRangeUnitTestsMap};

	_showTitle("TESTS MAP");
	_initializeResultTests(results);
	for (unsigned int count = 0; count < numberUnitTests; ++count)
		(*unitTests[count])(results);
	showResults(results);
}