// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.cpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 15:08:59 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 15:18:39 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

// **************************************** STATICS *** STATICS *** STATICS * //
// ************************* CONSTRUCTORS *** CONSTRUCTORS *** CONSTRUCTORS * //
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	Form("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "[RobotomyRequestForm](std::string const&)"
		" Ctor called" << std::endl;
	return ;
}

// **************************** DESTRUCTORS *** DESTRUCTORS *** DESTRUCTORS * //
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm]() Dtor called" << std::endl;
	return ;
}

// ********************************** OPERATORS *** OPERATORS *** OPERATORS * //
// **************************************** GETTERS *** GETTERS *** GETTERS * //
// **************************************** SETTERS *** SETTERS *** SETTERS * //
// ********************************** FUNCTIONS *** FUNCTIONS *** FUNCTIONS * //
void						RobotomyRequestForm::execute(
	Bureaucrat const &executor) const
{
	std::cout << "Makes some drilling noises. ";
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully"
				  << std::endl;
	else
		std::cout << "Robotomization failed on " << this->getTarget() <<
			std::endl;
	(void)executor;
	return ;
}


// ******************* NESTED_CLASSES *** NESTED_CLASSES *** NESTED_CLASSES * //
