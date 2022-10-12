/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSTD.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 00:53:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stackTests.hpp"
#include "stackTests.tpp"

int main(){
	std::stack<person> stackSTD;
	stackTests(stackSTD);
	return 0;
}