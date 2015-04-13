// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 14:11:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/13 18:27:18 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include "span.hpp"


#define DO_AND_PRINT(ARG)												\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;			\
	try { ARG }															\
	catch(std::exception &e) {std::cout << "\033[31mCatched:\033[0m"  << e.what()  << std::endl;} \
	catch(...) {std::cout << "\033[31mCatched:\033[0m unknown exception" << std::endl;}

#define JUST_PRINT(ARG)											\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;	

	

int							main(void)
{
	std::cout << "===============PART1:========" << std::endl;
	{
		Span sp(5);
	
		DO_AND_PRINT(sp.addNumber(5););
		DO_AND_PRINT(sp.addNumber(3););
		DO_AND_PRINT(sp.addNumber(17););
		DO_AND_PRINT(sp.addNumber(9););
		DO_AND_PRINT(sp.addNumber(11););
		DO_AND_PRINT(std::cout << sp.shortestSpan() << std::endl;);
		DO_AND_PRINT(std::cout << sp.longestSpan() << std::endl;);
	}
	std::cout << "===============PART2:========" << std::endl;
	
	
	Span		s(4);

	DO_AND_PRINT(std::cout << s.shortestSpan() << std::endl;);
	DO_AND_PRINT(s.addNumber(5););
	DO_AND_PRINT(std::cout << s.longestSpan() << std::endl;);
	DO_AND_PRINT(s.addNumber(7););
	DO_AND_PRINT(std::cout << s.shortestSpan() << std::endl;);
	DO_AND_PRINT(std::cout << s.longestSpan() << std::endl;);
	DO_AND_PRINT(s.addNumber(7););
	DO_AND_PRINT(s.addNumber(10););
	DO_AND_PRINT(s.addNumber(14););
	DO_AND_PRINT(std::cout << s.shortestSpan() << std::endl;);
	DO_AND_PRINT(std::cout << s.longestSpan() << std::endl;);
	DO_AND_PRINT(s.addNumber(19););
	
	
	return (0);
}
