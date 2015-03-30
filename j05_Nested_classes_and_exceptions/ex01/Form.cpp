// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 16:15:54 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 12:17:41 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Form.hpp"

// **************************************************** STATICS *** STATICS * //
const int                   Form::highestGrade = 1;
const int                   Form::lowestGrade = 150;
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Form::Form(std::string const &name, int sGrade, int eGrade)
	throw(GradeTooHighException, GradeTooLowException) :
	_name(name),
	_sGrade(sGrade),
	_eGrade(eGrade),
	_isSigned(false)
{
	std::cout << "[Form](std::string const&,int,int) Ctor called" << std::endl;
	if (sGrade < Form::highestGrade || eGrade < Form::highestGrade)
		throw GradeTooHighException();
	if (sGrade > Form::lowestGrade || eGrade > Form::lowestGrade)
		throw GradeTooLowException();
	return ;
}

// * NESTED-CLASSES ***************** //
Form::GradeTooHighException::GradeTooHighException() :
	std::exception()
{
	std::cout << "[GradeTooHighException]() Ctor called" << std::endl;
	return ;
}

Form::GradeTooLowException::GradeTooLowException() :
	std::exception()
{
	std::cout << "[GradeTooLowException]() Ctor called" << std::endl;
	return ;
}
Form::GradeTooHighException::GradeTooHighException(
	GradeTooHighException const &rhs) : std::exception()
{
	std::cout << "[GradeTooHighException](cpy) Ctor called" << std::endl;
	(void)rhs;
	return ;
}

Form::GradeTooLowException::GradeTooLowException(
	GradeTooLowException const &rhs) : std::exception()
{
	std::cout << "[GradeTooLowException](cpy) Ctor called" << std::endl;
	(void)rhs;
	return ;
}

// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Form::~Form()
{
	std::cout << "[Form]() Dtor called" << std::endl;
	return ;
}

// * NESTED-CLASSES ***************** //
Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "[GradeTooHighException]() Dtor called" << std::endl;
	return ;
}
Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "[GradeTooLowException]() Dtor called" << std::endl;
	return ;
}

// ************************************************ OPERATORS *** OPERATORS * //

std::ostream				&operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form(" << rhs.getSGrade() << "," << rhs.getEGrade() <<
		"):"<< rhs.getName() << " signed:" << std::boolalpha <<
		rhs.getIsSigned();
	return (o);
}

// **************************************************** GETTERS *** GETTERS * //

std::string const			&Form::getName(void) const{return this->_name;}
int							Form::getSGrade(void) const{return this->_sGrade;}
int							Form::getEGrade(void) const{return this->_eGrade;}
bool						Form::getIsSigned(void) const
{return this->_isSigned;}

// ************************************************************************** //

void						Form::beSigned(Bureaucrat const &b)
	throw(GradeTooLowException)
{
	if (!this->_isSigned)
	{
		if (b.getGrade() > this->_sGrade)
			throw Form::GradeTooLowException();
		this->_isSigned = true;
	}
	else
		std::cout << this->_name << " is already signed..." << std::endl;
	return ;
}


// * NESTED-CLASSES ***************** //
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
