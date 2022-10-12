/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorUnitTests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/11 10:46:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"


void vectorUnitTests(void){
	t_resultTests results;
	unsigned int numberUnitTests = 24;
	void(*unitTests[])(t_resultTests &results) = { sizeUnitTests, capacityUnitTests, \
		emptyUnitTests, maxSizeUnitTests, pushBackUnitTests, popBackUnitTests, \
		reserveUnitTests, clearUnitTests, resizeUnitTests, swapUnitTests, eraseUnitTests, \
		insertUnitTests, assignUnitTests, atUnitTests, backUnitTests, frontUnitTests, \
		beginUnitTests, endUnitTests, rbeginUnitTests, rendUnitTests, dataUnitTests,\
		constructorDefaultUnitTests, constructorFillUnitTests, constructorRangeUnitTests};

	_showTitle("TESTS VECTOR");
	_initializeResultTests(results);
	for (unsigned int count = 0; count < numberUnitTests; ++count)
		(*unitTests[count])(results);
	showResults(results);
}