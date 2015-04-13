// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 13:22:36 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/13 13:08:20 by ngoguey          ###   ########.fr       //
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

// * NESTED-CLASSES ***************** //
Intern::UnknownForm::UnknownForm() :
	std::exception()
{
	std::cout << "[UnknownForm]() Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Intern::~Intern()
{
	std::cout << "[Intern]() Dtor called" << std::endl;
	return ;
}

// * NESTED-CLASSES ***************** //
Intern::UnknownForm::~UnknownForm() throw()
{
	std::cout << "[UnknownForm]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
Form						*Intern::makeForm(std::string const &name, 
					std::string const &target) const
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
	else
		std::cout << "Intern doesnt know any \"" << name << "\"" << std::endl;
	if (ret != NULL)
		std::cout << "Intern creates " << ret->getName() << std::endl;
	else
		throw Intern::UnknownForm();
	return (ret);
}

// * NESTED_CLASSES ********************************************************* //
const char *Intern::UnknownForm::what() const throw()
{
	return ("Unknown form");
}
