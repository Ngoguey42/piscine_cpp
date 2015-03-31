// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.cpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 14:38:30 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 15:09:37 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "PresidentialPardonForm.hpp"

// **************************************** STATICS *** STATICS *** STATICS * //
// ************************* CONSTRUCTORS *** CONSTRUCTORS *** CONSTRUCTORS * //
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	Form("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "[PresidentialPardonForm](std::string const&)"
	" Ctor called" << std::endl;
	return ;
}

// **************************** DESTRUCTORS *** DESTRUCTORS *** DESTRUCTORS * //
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm]() Dtor called" << std::endl;
	return ;
}

// ********************************** OPERATORS *** OPERATORS *** OPERATORS * //
// **************************************** GETTERS *** GETTERS *** GETTERS * //
// **************************************** SETTERS *** SETTERS *** SETTERS * //
// ********************************** FUNCTIONS *** FUNCTIONS *** FUNCTIONS * //
void						PresidentialPardonForm::execute(
	Bureaucrat const &executor) const
{
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox."
			  << std::endl;
	(void)executor;
	return ;
}

// ******************* NESTED_CLASSES *** NESTED_CLASSES *** NESTED_CLASSES * //
