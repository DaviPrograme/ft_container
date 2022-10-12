/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 00:28:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TESTES_HPP
# define STACK_TESTES_HPP

# include <stdlib.h>
# include <time.h>
# include <stack>
# include <iomanip>
# include <iostream>
# include <typeinfo>
# include <math.h>
# include <algorithm>
# include "../../../containers/Stack.hpp"
# include "../../aux/auxTests.hpp"

//funcoes de benchmark
void stackBenchmark(void);
double constructorDefaultBenchmarkStack(std::string typeMap);
double topBenchmarkStack(std::string typeStack);
double emptyBenchmarkStack(std::string typeStack);
double sizeBenchmarkStack(std::string typeStack);
double pushBenchmarkStack(std::string typeStack);
double popBackBenchmarkStack(std::string typeStack);

//funcoes de teste
void stackUnitTests(void);
void constructorDefaultUnitTestsStack(t_resultTests &results);
void topUnitTestsStack(t_resultTests &results);
void emptyUnitTestsStack(t_resultTests &results);
void sizeUnitTestsStack(t_resultTests &results);
void pushUnitTestsStack(t_resultTests &results);
void popUnitTestsStack(t_resultTests &results);

#endif