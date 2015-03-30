// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 11:58:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 15:28:52 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <ctime>

int							main(void)
{
	Bureaucrat		b("Connard", Bureaucrat::lowestGrade);
	Bureaucrat		bo("Boss", Bureaucrat::highestGrade);
	Form			*form1 = new PresidentialPardonForm("Zizou");
	Form			*form2 = new RobotomyRequestForm("Joseph");
	Form			*form3 = new ShrubberyCreationForm("Living_room");

	std::cout << std::endl;	
	bo.executeForm(*form1);
	std::cout << std::endl;
	bo.signForm(*form1);
	std::cout << std::endl;
	b.executeForm(*form1);
	std::cout << std::endl;
	bo.executeForm(*form1);
	std::cout << std::endl;
	std::cout << std::endl;	
	std::cout << std::endl;	
	
	srand(time(NULL));
	bo.executeForm(*form2);
	std::cout << std::endl;
	bo.signForm(*form2);
	std::cout << std::endl;
	b.executeForm(*form2);
	std::cout << std::endl;
	bo.executeForm(*form2);
	bo.executeForm(*form2);
	bo.executeForm(*form2);
	std::cout << std::endl;
	std::cout << std::endl;	
	std::cout << std::endl;
	
	bo.executeForm(*form3);
	std::cout << std::endl;
	bo.signForm(*form3);
	std::cout << std::endl;
	b.executeForm(*form3);
	std::cout << std::endl;
	bo.executeForm(*form3);
	std::cout << std::endl;	
	delete form1;
	delete form2;
	delete form3;
	return (0);
}
