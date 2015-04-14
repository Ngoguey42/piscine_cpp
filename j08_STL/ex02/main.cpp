// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 14:11:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/14 12:46:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <algorithm>
// #include <ctime>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include "MutantStack.hpp"


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
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); mstack.push(0);
		// MutantStack<int>::iterator it = mstack.begin();

		// std::cout << *it << std::endl;
		
		
		MutantStack<int>::iterator ite = mstack.end();
		// ++it;
		// --it;
		// while (it != ite) {
		// 	std::cout << *it << std::endl;
		// 	++it; }
		// std::stack<int> s(mstack);MutantStack<int> mstack; mstack.push(5);
		// mstack.push(17);
		// std::cout << mstack.top() << std::endl;
		// mstack.pop();
		// std::cout << mstack.size() << std::endl;
		// mstack.push(3); mstack.push(5); mstack.push(737); mstack.push(0);
		// MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
		// ++it;
		// --it;
		// while (it != ite) {
		// 	std::cout << *it << std::endl;
		// 	++it; }
		// std::stack<int> s(mstack);



		std::cout << *ite << std::endl;
	}

	
	return (0);
}
