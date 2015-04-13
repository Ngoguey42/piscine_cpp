// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 14:11:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/13 14:48:13 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include "easyfind.hpp"


#define DO_AND_PRINT(ARG)\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;\
	try { ARG }\
	catch(std::exception &e) {std::cout << "\033[31mCatched:\033[0m"  << e.what()  << std::endl;} \
	catch(...) {std::cout << "\033[31mCatched:\033[0m unknown exception" << std::endl;}\
	std::cout << std::endl;

	
	

int							main(void)
{
	std::vector<int>		vector;

	DO_AND_PRINT(
	for (int i = 1; i < 1000 * 1000 * 1000; i *= 42)
		vector.push_back(i););

	DO_AND_PRINT(std::copy(vector.begin(), vector.end(),
						   std::ostream_iterator<int>(std::cout, "\n")););
	DO_AND_PRINT(easyfind< std::vector<int> >(vector, 42););
	DO_AND_PRINT(easyfind< std::vector<int> >(vector, 43););
	

	std::list<int>		list;

	DO_AND_PRINT(
	for (int i = 1; i < 1000 * 1000 * 1000; i *= 42)
		list.push_back(i););

	DO_AND_PRINT(std::copy(list.begin(), list.end(),
						   std::ostream_iterator<int>(std::cout, "\n")););
	DO_AND_PRINT(easyfind< std::list<int> >(list, 130691232););
	DO_AND_PRINT(easyfind< std::list<int> >(list, 130691233););
	

	std::deque<int>		deque;

	DO_AND_PRINT(
	for (int i = 1; i < 1000 * 1000 * 1000; i *= 42)
		deque.push_back(i););

	DO_AND_PRINT(std::copy(deque.begin(), deque.end(),
						   std::ostream_iterator<int>(std::cout, "\n")););
	DO_AND_PRINT(easyfind< std::deque<int> >(deque, 74088););
	DO_AND_PRINT(easyfind< std::deque<int> >(deque, 0););
	

	return (0);
}
