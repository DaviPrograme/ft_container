/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 00:53:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stackTests.hpp"
#include "stackTests.tpp"

int main(){
	ft::stack<person> stackFT;
	stackTests(stackFT);
	return 0;
}