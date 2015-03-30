// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 15:24:30 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 15:43:43 by ngoguey          ###   ########.fr       //
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
	std::string		filename(this->getTarget());
	std::ofstream	ofs;

	filename += "_shrubbery";
	filename = "/";
	try
	{
		ofs.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
		ofs << "bordel";
		std::cout << filename << std::endl;
	}
	catch (std::exception &e)
	// catch (std::ofstream::failure &e)
	{
		std::cout << "Error handling " << filename << ": " <<
			e.what() << std::endl;
	}
	(void)executor;
	return ;
}

// ******************* NESTED_CLASSES *** NESTED_CLASSES *** NESTED_CLASSES * //
