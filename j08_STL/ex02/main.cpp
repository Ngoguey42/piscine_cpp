// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 14:11:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/14 14:13:48 by ngoguey          ###   ########.fr       //
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
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		{
			std::cout << std::endl;
			
			std::cout << "iterating through mutantstacks" << std::endl;
			
			MutantStack<int>::iterator it = mstack.begin();
			it.printAdress();
			MutantStack<int>::iterator ite = mstack.end();

			++it;
			--it;
			
			while (it != ite) {
				std::cout << "\t" << *it << std::endl;
				++it; }
			std::cout << "finished iterating through mutantstacks" << std::endl << std::endl;
		}
		
		std::cout << "new stack 's' with copy constructor:" << std::endl;
		std::stack<int> s(mstack);
		std::cout << "printing/poping stack 's':" << std::endl;
		while (s.size() > 0) {
			std::cout << "\t" <<  s.top() << std::endl;
			s.pop();
		}
		
		(void)s;
	}

	
	return (0);
}
