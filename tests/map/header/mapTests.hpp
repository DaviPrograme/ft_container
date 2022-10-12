/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:42:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TESTES_HPP
# define MAP_TESTES_HPP

# include <stdlib.h>
# include <time.h>
# include <map>
# include <iomanip>
# include <iostream>
# include <typeinfo>
# include <math.h>
# include <algorithm>
# include <utility>
# include "../../../containers/Map.hpp"
# include "../../aux/auxTests.hpp"

//funcoes de benchmark
void mapBenchmark(void);
double constructorDefaultBenchmarkMap(std::string typeMap);
double constructorCopyBenchmarkMap(std::string typeMap);
double constructorRangeBenchmarkMap(std::string typeMap);
double insertBenchmarkMap1(std::string typeMap);
double insertBenchmarkMap2(std::string typeMap);
double insertBenchmarkMap3(std::string typeMap);
double sizeBenchmarkMap(std::string typeMap);
double beginBenchmarkMap(std::string typeMap);
double endBenchmarkMap(std::string typeMap);
double rendBenchmarkMap(std::string typeMap);
double rbeginBenchmarkMap(std::string typeMap);
double emptyBenchmarkMap(std::string typeMap);
double maxSizeBenchmarkMap(std::string typeMap);
double atBenchmarkMap(std::string typeMap);
double operatorArrayBenchmarkMap(std::string typeMap);
double clearBenchmarkMap(std::string typeVector);
double erase1BenchmarkMap(std::string typeMap);
double erase2BenchmarkMap(std::string typeMap);
double erase3BenchmarkMap(std::string typeMap);
double swapBenchmarkMap(std::string typeVector);
double countBenchmarkMap(std::string typeVector);
double findBenchmarkMap(std::string typeMap);
double lowerBoundBenchmarkMap(std::string typeMap);
double upperBoundBenchmarkMap(std::string typeMap);
double equalRangeBenchmarkMap(std::string typeMap);
double valueCompBenchmarkMap(std::string typeMap);
double getAllocatorBenchmarkMap(std::string typeMap);
double keyCompBenchmarkMap(std::string typeMap);


//funcoes de teste
void mapUnitTests(void);
void constructorDefaultUnitTestsMap(t_resultTests &results);
void constructorCopyUnitTestsMap(t_resultTests &results);
void constructorRangeUnitTestsMap(t_resultTests &results);
void insertUnitTestsMap(t_resultTests &results);
void sizeUnitTestsMap(t_resultTests &results);
void beginUnitTestsMap(t_resultTests &results);
void endUnitTestsMap(t_resultTests &results);
void rendUnitTestsMap(t_resultTests &results);
void rbeginUnitTestsMap(t_resultTests &results);
void emptyUnitTestsMap(t_resultTests &results);
void maxSizeUnitTestsMap(t_resultTests &results);
void atUnitTestsMap(t_resultTests &results);
void operatorArrayUnitTestsMap(t_resultTests &results);
void clearUnitTestsMap(t_resultTests &results);
void eraseUnitTestsMap(t_resultTests &results);
void swapUnitTestsMap(t_resultTests &results);
void countUnitTestsMap(t_resultTests &results);
void findUnitTestsMap(t_resultTests &results);
void lowerBoundUnitTestsMap(t_resultTests &results);
void upperBoundUnitTestsMap(t_resultTests &results);
void equalRangeUnitTestsMap(t_resultTests &results);
void constructorRangeUnitTestsMap(t_resultTests &results);
void valueCompUnitTestsMap(t_resultTests &results);
void getAllocatorUnitTestsMap(t_resultTests &results);
void KeyCompUnitTestsMap(t_resultTests &results);


//funcoes auxiliares
bool compareElementsMap(std::map<int, char> &mapOriginal, ft::map<int, char> &mapFake);
void manyInsertElements(unsigned int countElements, std::map<int, char> &mapOriginal, ft::map<int, char> &mapFake);
void manyInsertElements(unsigned int countElements, std::map<int, char> &mapOriginal);
void manyInsertElements(unsigned int countElements, ft::map<int, char> &mapFake);

#endif