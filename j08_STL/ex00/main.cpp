// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 14:11:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/13 16:12:42 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include "easyfind.hpp"


#define DO_AND_PRINT(ARG)												\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;			\
	try { ARG }															\
	catch(std::exception &e) {std::cout << "\033[31mCatched:\033[0m"  << e.what()  << std::endl;} \
	catch(...) {std::cout << "\033[31mCatched:\033[0m unknown exception" << std::endl;}	\
	std::cout << std::endl;

#define JUST_PRINT(ARG)											\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;	

void mapPrint(std::pair<const int, int>& pair)
{
	std::cout << "k = " << pair.first << "  v = " << pair.second << std::endl;
	return ;
}
void map2Print(std::pair<const char, int>& pair)
{
	std::cout << "k = " << pair.first << "  v = " << pair.second << std::endl;
	return ;
}
	

int							main(void)
{
	std::cout << "===========VECTOR==============" << std::endl;
	
	std::vector<int>		vector;

	DO_AND_PRINT(
		for (int i = 1; i < 1000 * 1000 * 1000; i *= 42)
			vector.push_back(i););
	DO_AND_PRINT(std::copy(vector.begin(), vector.end(),
						   std::ostream_iterator<int>(std::cout, "\n")););
	DO_AND_PRINT(easyfind< std::vector<int> >(vector, 42););
	DO_AND_PRINT(easyfind(vector, 43););
	
	std::cout << "============LIST=============" << std::endl;
	
	std::list<int>		list;

	DO_AND_PRINT(
		for (int i = 1; i < 1000 * 1000 * 1000; i *= 42)
			list.push_back(i););
	DO_AND_PRINT(std::copy(list.begin(), list.end(),
						   std::ostream_iterator<int>(std::cout, "\n")););
	DO_AND_PRINT(easyfind< std::list<int> >(list, 130691232););
	DO_AND_PRINT(easyfind< std::list<int> >(list, 130691233););
	

	std::cout << "============DEQUE=============" << std::endl;
	std::deque<int>		deque;

	DO_AND_PRINT(
		for (int i = 1; i < 1000 * 1000 * 1000; i *= 42)
			deque.push_back(i););
	DO_AND_PRINT(std::copy(deque.begin(), deque.end(),
						   std::ostream_iterator<int>(std::cout, "\n")););
	DO_AND_PRINT(easyfind< std::deque<int> >(deque, 74088););
	DO_AND_PRINT(easyfind< std::deque<int> >(deque, 0););
	

	std::cout << "============SET1=============" << std::endl;
	std::set<int>		set1;

	DO_AND_PRINT(
		for (int i = 1; i < 1000 * 1000 * 1000; i *= 42)
			set1.insert(i););
	DO_AND_PRINT(std::copy(set1.begin(), set1.end(),
						   std::ostream_iterator<int>(std::cout, "\n")););
	DO_AND_PRINT(easyfind< std::set<int> >(set1, 74088););
	DO_AND_PRINT(easyfind< std::set<int> >(set1, 0););	

	std::cout << "============SET2=============" << std::endl;
	std::set<char>		set2;

	DO_AND_PRINT(
		for (char i = 'A'; i < 'F'; i++)
			set2.insert(i););
	DO_AND_PRINT(std::copy(set2.begin(), set2.end(),
						   std::ostream_iterator<char>(std::cout, "\n")););
	DO_AND_PRINT(easyfind< std::set<char> >(set2, 'B'););
	DO_AND_PRINT(easyfind< std::set<char> >(set2, 0););	


	std::cout << "===========MAP1==============" << std::endl;
	std::map<int, int>		map;

	DO_AND_PRINT(
		for (int i = 1; i < 1000 * 1000 * 1000; i *= 42)
			map.insert(std::pair<int,int>(i, i)););
	DO_AND_PRINT(for_each(map.begin(), map.end(), &mapPrint););
	DO_AND_PRINT(easyfind< int >(map, 42););
	DO_AND_PRINT(easyfind(map, 44););
	

	std::cout << "===========MAP2==============" << std::endl;
	std::map<char, int>		map2;

	DO_AND_PRINT(
		for (int i = 1, c = 'a'; i < 1000 * 1000 * 1000; i *= 42, c++)
			map2.insert(std::pair<char,int>((char)c, i)););
	DO_AND_PRINT(for_each(map2.begin(), map2.end(), &map2Print););
	DO_AND_PRINT(easyfind< char >(map2, 0););
	DO_AND_PRINT(easyfind(map2, 42););
	
	return (0);
}
