/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAuxTests.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/10/10 19:48:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vectorTests.hpp"

template<class T, class U>
void copyElementsVector(T &src, U &dst){
	typename T::iterator itStart;
	typename T::iterator itEnd;
	itStart = src.begin();
	itEnd = src.end();

	while(itStart != itEnd){
		dst.push_back(*itStart);
		++itStart;
	}
}

template<class T, class U>
bool compareElementsVectors(T &vectorOriginal, U &vectorFake){
	typename T::iterator it;
	typename U::iterator fit;
	it = vectorOriginal.begin();
	fit = vectorFake.begin();
	unsigned int count = 0;
	while(count < vectorOriginal.size()){
		if (*it != *fit)
			return false;
		++count;
		++it;
		++fit;
	}
	return true;
}

template<class T>
void manyPushBacksInts(unsigned int countElements, T &vector){
	int random;
	unsigned int count = 0;

	while(++count <= countElements){
		srand((unsigned)time(NULL));
		random = std::rand() % 100000;
		vector.push_back(random);
	}	
}

template<class T>
void popBackAllElements(T &vector){
	typename T::iterator itStart;
	typename T::iterator itEnd;
	itStart = vector.begin();
	itEnd = vector.end();
	while(itStart != itEnd){
		vector.pop_back();
		itEnd = vector.end();
	}
}