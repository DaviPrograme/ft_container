/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackUnitTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:46:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stackTests.hpp"


void stackUnitTests(void){
	t_resultTests results;
	unsigned int numberUnitTests = 5;
	void(*unitTests[])(t_resultTests &results) = { constructorDefaultUnitTestsStack, \
	topUnitTestsStack, emptyUnitTestsStack, sizeUnitTestsStack, pushUnitTestsStack};

	_showTitle("TESTS STACK");
	_initializeResultTests(results);
	for (unsigned int count = 0; count < numberUnitTests; ++count)
		(*unitTests[count])(results);
	showResults(results);
}