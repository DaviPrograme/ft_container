/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSTD.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/07 01:48:18 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/mapTests.hpp"
#include "mapTests.tpp"

int main(){
	std::map<int, person> mapSTD;
	mapTests(mapSTD);
	return 0;
}