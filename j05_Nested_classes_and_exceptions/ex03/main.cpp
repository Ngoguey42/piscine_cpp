// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 11:58:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 09:21:37 by ngoguey          ###   ########.fr       //
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

	std::cout << "i.makeForm(\"Test SuC\", \"targ\");" << std::endl;
	i.makeForm("Test SuC", "targ");
	std::cout << std::endl;
	
	std::cout << "i.makeForm(\"robotomy request\", \"Bender\");" << std::endl;
	i.makeForm("robotomy request", "Bender");
	std::cout << std::endl;

	std::cout << "i.makeForm(\"robotomy requesTFORM\", \"Bender\");" << std::endl;
	i.makeForm("robotomy requesTFORM", "Bender");
	std::cout << std::endl;
	
	std::cout << "i.makeForm(\"robotomy request form\", \"Bender\");" << std::endl;
	i.makeForm("robotomy request form", "Bender");
	std::cout << std::endl;
	
	std::cout << "i.makeForm(\"shrubberycreation\", \"Bender\");" << std::endl;
	i.makeForm("shrubberycreation", "Bender");
	std::cout << std::endl;

	std::cout << "i.makeForm(\"presidenLOLtialpardon\", \"Bender\");" << std::endl;
	i.makeForm("presidenLOLtialpardon", "Bender");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "i.makeForm(\"presidentialpardon\", \"Bender\");" << std::endl;
	f = i.makeForm("presidentialpardon", "Bender");
	std::cout << std::endl;
	
	bo.signForm(*f);
	std::cout << std::endl;
	
	bo.executeForm(*f);
	std::cout << std::endl;
	std::cout << std::endl;
	
	
	
	(void)b;
	(void)bo;
	return (0);
}
