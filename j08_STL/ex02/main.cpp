// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 14:11:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/17 12:00:12 by ngoguey          ###   ########.fr       //
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


// #define USE_STD_LIST // comment/uncomment

#ifndef USE_STD_LIST //DONT TOUCH
# define CONTAINERTYPE MutantStack
# define SECOND_CONTAINERTYPE std::stack
# define POP_INSTRUCTION pop
# define PUSH_INSTRUCTION push
# define TOP_INSTRUCTION top
#else
# define CONTAINERTYPE std::list
# define SECOND_CONTAINERTYPE std::list
# define POP_INSTRUCTION pop_back
# define PUSH_INSTRUCTION push_back
# define TOP_INSTRUCTION back
#endif

int							main(void)
{
	std::cout << "===============PART1:========" << std::endl;
	{
		
		CONTAINERTYPE<int> mstack;

		mstack.PUSH_INSTRUCTION(5);
		mstack.PUSH_INSTRUCTION(17);
		
		std::cout << mstack.TOP_INSTRUCTION() << std::endl;
		
		mstack.POP_INSTRUCTION();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.PUSH_INSTRUCTION(3);
		mstack.PUSH_INSTRUCTION(5);
		mstack.PUSH_INSTRUCTION(737);
		mstack.PUSH_INSTRUCTION(0);

		{
			std::cout << std::endl;
			
			std::cout << "creating iterator on begin" << std::endl;
			CONTAINERTYPE<int>::iterator it = mstack.begin();
			std::cout << "created iterator on begin" << std::endl;
#ifndef USE_STD_LIST
			it.printAdress();
#endif
			std::cout << "creating iterator on end" << std::endl;
			CONTAINERTYPE<int>::iterator ite = mstack.end();
			std::cout << "created iterator on end" << std::endl;
			
			std::cout << "testing iterator unary operators" << std::endl;
			
			++it;
			--it;
			it++;
			it--;

			--it;
			++it;
			it--;
			it++;
			
			while (it != ite) {
				std::cout << "\t" << *it << std::endl;
				++it; }
			std::cout << "finished iterating through mutantstacks" << std::endl << std::endl;
		}
		
		std::cout << "new stack 's' with copy constructor:" << std::endl;
		SECOND_CONTAINERTYPE<int> s(mstack);
		std::cout << "printing/POP_INSTRUCTIONing stack 's':" << std::endl;
		while (s.size() > 0) {
			std::cout << "\t" <<  s.TOP_INSTRUCTION() << std::endl;
			s.POP_INSTRUCTION();
		}
		
	}

	
	return (0);
}
