/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapAuxTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/05 01:36:55 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mapTests.hpp"

bool compareElementsMap(std::map<int, char> &mapOriginal, ft::map<int, char> &mapFake){
	std::map<int, char>::iterator it;
	ft::map<int, char>::iterator fit;

	it = mapOriginal.begin();
	fit = mapFake.begin();
	unsigned int count = 0;
	while(count < mapOriginal.size()){
		if (it->first != fit->first || it->second != fit->second)
			return false;
		++it;
		++fit;
		++count;
	}
	return true;
}

void manyInsertElements(unsigned int countElements, std::map<int, char> &mapOriginal, ft::map<int, char> &mapFake){
	unsigned int count = 0;

	while(count < countElements){
		mapOriginal.insert(std::make_pair(count, '!' + (count % 94)));
		mapFake.insert(ft::make_pair(count, '!' + (count % 94)));
		++count;
	}	
}

void manyInsertElements(unsigned int countElements, std::map<int, char> &mapOriginal){
	unsigned int count = 0;

	while(count < countElements){
		mapOriginal.insert(std::make_pair(count, '!' + (count % 94)));
		++count;
	}	
}

void manyInsertElements(unsigned int countElements, ft::map<int, char> &mapFake){
	unsigned int count = 0;

	while(count < countElements){
		mapFake.insert(ft::make_pair(count, '!' + (count % 94)));
		++count;
	}	
}