/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/07 01:48:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/mapTests.hpp"
#include "mapTests.tpp"

int main(){
	ft::map<int, person> mapFT;
	mapTests(mapFT);
	return 0;
}