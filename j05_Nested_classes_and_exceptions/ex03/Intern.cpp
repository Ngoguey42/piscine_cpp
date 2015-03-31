// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 13:22:36 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 13:46:15 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Intern.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
Intern::Intern()
{
	std::cout << "[Intern]() Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Intern::~Intern()
{
	std::cout << "[Intern]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
Form						*Intern::makeForm(std::string const &name, 
											  std::string const &target)
{
	std::string		copy(name);
	Form			*ret = NULL;

	for (std::string::iterator it = copy.begin(); it != copy.end();)
	{
		if (*it == ' ' || *it == '\t')
			copy.erase(it);
		else
		{
			*it = std::tolower(*it);
			it++;
		}
	}
	if (copy.length() > 6 && copy.find("form", copy.length() - 5, 4) !=
		std::string::npos)
		copy = copy.erase(copy.length() - 4, 4);
	if (copy == "presidentialpardon")
		ret = new PresidentialPardonForm(target);
	else if (copy == "robotomyrequest")
		ret = new RobotomyRequestForm(target);
	else if (copy == "shrubberycreation")
		ret = new ShrubberyCreationForm(target);
	if (ret != NULL)
		std::cout << "Intern creates " << ret->getName() << std::endl;
	return (ret);
}

// * NESTED_CLASSES ********************************************************* //
