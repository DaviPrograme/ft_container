/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSTD.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/07/14 00:47:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/vectorTests.hpp"
#include "vectorTests.tpp"

int main(){
	std::vector<person> vectorSTD;
	vectorTests(vectorSTD);
	return 0;
}