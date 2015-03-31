// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 15:24:30 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 06:51:53 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include <fstream>

// **************************************** STATICS *** STATICS *** STATICS * //
// ************************* CONSTRUCTORS *** CONSTRUCTORS *** CONSTRUCTORS * //
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	Form("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "[ShrubberyCreationForm](std::string const&)"
		" Ctor called" << std::endl;
	return ;
}

// **************************** DESTRUCTORS *** DESTRUCTORS *** DESTRUCTORS * //
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm]() Dtor called" << std::endl;
	return ;
}

// ********************************** OPERATORS *** OPERATORS *** OPERATORS * //
// **************************************** GETTERS *** GETTERS *** GETTERS * //
// **************************************** SETTERS *** SETTERS *** SETTERS * //
// ********************************** FUNCTIONS *** FUNCTIONS *** FUNCTIONS * //
void						ShrubberyCreationForm::execute(
	Bureaucrat const &executor) const
{
	std::string		filename("./");
	std::ofstream	ofs;

	filename += this->getTarget();
	filename += "_shrubbery";
	ofs.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail())
	{
		std::cout << "Error openning " << filename << std::endl;
		return ;
	}
	ofs <<
		"  xxxxx xxxxxxxxx xxxx xxxxxxxxxx xx" << std::endl <<
		"   YYY   YYYYYYY   YY   YYYYYYY   YY" << std::endl <<
		"   ---   -------   --   -------   --" << std::endl <<
		"    |       ||     ||     |||     ||" << std::endl <<
		"    |       ||     ||     |||     ||" << std::endl <<
		"    |       ||     ||     |||     ||" << std::endl;
	if (ofs.fail())
	{
		std::cout << "Error writting in  " << filename << std::endl;
		return ;
	}
	(void)executor;
	return ;
}

// ******************* NESTED_CLASSES *** NESTED_CLASSES *** NESTED_CLASSES * //
