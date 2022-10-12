/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxTests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:42:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_TESTES_HPP
# define CONFIG_TESTES_HPP
# define KO "\033[1;31m"
# define OK "\033[1;32mOK\033[0m"
# define GREEN "\033[1;32m"
# define WARNING "\033[33m"
# define WHITE "\033[0m"
# define TITLE "\033[1;35m"
# define TIME_PRECISION 3

# include <iostream>


typedef struct s_resultTests {
	unsigned int countRightTests;
	unsigned int countWrongTests;
} t_resultTests;

//funcoes auxiliares
std::string titleTest(std::string str);
void _subTitle(std::string subTitle);
void _showResultsBenchmarkTests(double &timeSTD, double &timeFT);
void _runBenchmarkTest(double (*benchmarkTest)(std::string type), double &accumulatedSTD, double &accumulatedFT);
void showResults(t_resultTests &results);
void _showTitle(std::string title);
void _initializeResultTests(t_resultTests &results);

#endif