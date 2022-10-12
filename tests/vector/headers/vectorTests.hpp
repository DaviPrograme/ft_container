/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/11 10:45:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTES_HPP
# define VECTOR_TESTES_HPP

# include <stdlib.h>
# include <time.h>
# include <vector>
# include <iomanip>
# include <iostream>
# include <typeinfo>
# include <math.h>
# include <algorithm>
# include "../../../containers/Vector.hpp"
# include "../../aux/auxTests.hpp"

//funcoes de benchmark
void vectorBenchmark(void);
double pushBackBenchmark(std::string typeVector);
double popBackBenchmark(std::string typeVector);
double sizeBenchmark(std::string typeVector);
double capacityBenchmark(std::string typeVector);
double emptyBenchmark(std::string typeVector);
double reserveBenchmark(std::string typeVector);
double clearBenchmark(std::string typeVector);
double maxSizeBenchmark(std::string typeVector);
double resizeBenchmark(std::string typeVector);
double swapBenchmark(std::string typeVector);
double eraseBenchmark1(std::string typeVector);
double eraseBenchmark2(std::string typeVector);
double insertBenchmark1(std::string typeVector);
double insertBenchmark2(std::string typeVector);
double insertBenchmark3(std::string typeVector);
double assignBenchmark1(std::string typeVector);
double assignBenchmark2(std::string typeVector);
double atBenchmark(std::string typeVector);
double backBenchmark(std::string typeVector);
double frontBenchmark(std::string typeVector);
double beginBenchmark(std::string typeVector);
double endBenchmark(std::string typeVector);
double rbeginBenchmark(std::string typeVector);
double rendBenchmark(std::string typeVector);
double dataBenchmark(std::string typeVector);
double constructorDefaultBenchmark(std::string typeVector);
double constructorFillBenchmark(std::string typeVector);
double constructorRangeBenchmark(std::string typeVector);



//funcoes de teste
void vectorUnitTests(void);
void pushBackUnitTests(t_resultTests &results);
void popBackUnitTests(t_resultTests &results);
void sizeUnitTests(t_resultTests &results);
void capacityUnitTests(t_resultTests &results);
void emptyUnitTests(t_resultTests &results);
void reserveUnitTests(t_resultTests &results);
void clearUnitTests(t_resultTests &results);
void maxSizeUnitTests(t_resultTests &results);
void resizeUnitTests(t_resultTests &results);
void swapUnitTests(t_resultTests &results);
void eraseUnitTests(t_resultTests &results);
void insertUnitTests(t_resultTests &results);
void assignUnitTests(t_resultTests &results);
void atUnitTests(t_resultTests &results);
void backUnitTests(t_resultTests &results);
void frontUnitTests(t_resultTests &results);
void beginUnitTests(t_resultTests &results);
void endUnitTests(t_resultTests &results);
void rbeginUnitTests(t_resultTests &results);
void rendUnitTests(t_resultTests &results);
void dataUnitTests(t_resultTests &results);
void constructorDefaultUnitTests(t_resultTests &results);
void constructorFillUnitTests(t_resultTests &results);
void constructorRangeUnitTests(t_resultTests &results);


//funcoes auxiliares

template<class T, class U>
void copyElementsVector(T &src, U &dst);

template<class T, class U>
bool compareElementsVectors(T &vectorOriginal, U &vectorFake);

template<class T>
void manyPushBacksInts(unsigned int countElements, T &vector);

template<class T>
void popBackAllElements(T &vector);


#include "../src/vectorAuxTests.tpp"
#endif