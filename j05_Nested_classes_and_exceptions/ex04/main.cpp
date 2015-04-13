// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 11:58:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/13 13:07:29 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <cstdlib>
#include <ctime>

int							main(void)
{
	/*
	  Form("PresidentialPardonForm", 25, 5, target)
	  Form("RobotomyRequestForm", 72, 45, target)
	  Form("ShrubberyCreationForm", 145, 137, target)
	*/
	Bureaucrat		b("Connard", Bureaucrat::lowestGrade);
	Bureaucrat		bo("Boss", Bureaucrat::highestGrade);
	Intern			in;
	Form			*f;

	OfficeBlock		*ob1;
	OfficeBlock		*ob2;

#define DO_AND_PRINT(ARG)												\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;			\
	try { ARG }															\
	catch(std::exception &e) {std::cout << "\033[31mCatched:\033[0m"  << e.what()  << std::endl;} \
	catch(...) {	std::cout << "\033[31mCatched:\033[0m unknown exception" << std::endl;}		\
	std::cout << std::endl;
	
//	catch(Intern::UnknownForm &e) {std::cout << e.what() << std::endl;}
	
	DO_AND_PRINT(ob2 = new OfficeBlock(&in, &b, &bo););
	DO_AND_PRINT(ob2->doBureaucracy("truc", "Victimlol"););

	std::cout <<  std::endl;
	std::cout <<  std::endl;

	
	DO_AND_PRINT(ob1 = new OfficeBlock(););
	DO_AND_PRINT(ob1->doBureaucracy("Shrubbery Creation Form", "Victimlol"););
	DO_AND_PRINT(ob1->setIntern(&in););
	DO_AND_PRINT(ob1->doBureaucracy("Shrubbery Creation Form", "Victimlol"););
	DO_AND_PRINT(ob1->setSigner(&bo););
	DO_AND_PRINT(ob1->doBureaucracy("Shrubbery Creation Form", "Victimlol"););

	DO_AND_PRINT(ob1->setExecuter(&b););
	DO_AND_PRINT(ob1->doBureaucracy("Shrubbery Creation Form", "Victimlol"););
	
	DO_AND_PRINT(ob1->setExecuter(&bo););
	DO_AND_PRINT(ob1->doBureaucracy("Shrubbery Creation Form", "Victimlol"););
	
	
	
	(void)b;
	(void)bo;
// (void)ob;
	(void)ob2;
	(void)in;
	(void)f;
	return (0);
}
