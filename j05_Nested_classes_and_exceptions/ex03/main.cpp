// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 11:58:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 13:37:19 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int							main(void)
{
	Bureaucrat		b("Connard", Bureaucrat::lowestGrade);
	Bureaucrat		bo("Boss", Bureaucrat::highestGrade);
	Form			*f;
	
	Intern			i;
	std::cout << std::endl;

	std::cout << "f = i.makeForm(\"Test SuC\", \"targ\");" << std::endl;
	f = i.makeForm("Test SuC", "targ");
	std::cout << "f == " << (void*)f << std::endl;
	std::cout << std::endl;
	
	
	std::cout << "f = i.makeForm(\"robotomy request\", \"Bender\");" << std::endl;
	f = i.makeForm("robotomy request", "Bender");
	std::cout << "f == " << (void*)f << std::endl; delete f;
	std::cout << std::endl;

	std::cout << "f = i.makeForm(\"robotomy requesTFORM\", \"Bender\");" << std::endl;
	f = i.makeForm("robotomy requesTFORM", "Bender");
	std::cout << "f == " << (void*)f << std::endl; delete f;
	std::cout << std::endl;
	
	std::cout << "f = i.makeForm(\"robotomy request form\", \"Bender\");" << std::endl;
	f = i.makeForm("robotomy request form", "Bender");
	std::cout << "f == " << (void*)f << std::endl; delete f;
	std::cout << std::endl;
	
	std::cout << "f = i.makeForm(\"shrubberycreation\", \"Bender\");" << std::endl;
	f = i.makeForm("shrubberycreation", "Bender");
	std::cout << "f == " << (void*)f << std::endl; delete f;
	std::cout << std::endl;

	std::cout << "f = i.makeForm(\"presidenLOLtialpardon\", \"Bender\");" << std::endl;
	f = i.makeForm("presidenLOLtialpardon", "Bender");
	std::cout << "f == " << (void*)f << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "f = i.makeForm(\"presidentialpardon\", \"Bender\");" << std::endl;
	f = i.makeForm("presidentialpardon", "Bender");
	std::cout << "f == " << (void*)f << std::endl;
	std::cout << std::endl;
	
	bo.signForm(*f);
	std::cout << std::endl;
	
	bo.executeForm(*f);
	 delete f;
	std::cout << std::endl;
	std::cout << std::endl;
	
	
	
	(void)b;
	(void)bo;
	return (0);
}
