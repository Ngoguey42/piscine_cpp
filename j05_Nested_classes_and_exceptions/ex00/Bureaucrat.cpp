// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 10:50:43 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/13 15:11:53 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
const int					Bureaucrat::highestGrade = 1;
const int					Bureaucrat::lowestGrade = 150;
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Bureaucrat::Bureaucrat() :
	_name("NoName"), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "[Bureaucrat]() Ctor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) :
	_name(src.getName()), _grade(src.getGrade())
{
	std::cout << "[Bureaucrat](cpy) Ctor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const &name, int startGrade) :
	_name(name), _grade(startGrade)
{
	if (startGrade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	if (startGrade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "[Bureaucrat](main) Ctor called" << std::endl;
			return ;
}

// * NESTED-CLASSES ***************** //
Bureaucrat::GradeTooHighException::GradeTooHighException() throw() :
	std::exception()
{
	std::cout << "[GradeTooHighException]() Ctor called" << std::endl;
	return ;
}
Bureaucrat::GradeTooHighException::GradeTooHighException
(Bureaucrat::GradeTooHighException const &src) throw() :
	std::exception()
{
	std::cout << "[GradeTooHighException](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() :
	std::exception()
{
	std::cout << "[GradeTooLowException]() Ctor called" << std::endl;
	return ;
}
Bureaucrat::GradeTooLowException::GradeTooLowException
(Bureaucrat::GradeTooLowException const &src) throw() :
	std::exception()
{
	std::cout << "[GradeTooLowException](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat]() Dtor called" << std::endl;
	return ;
}

// * NESTED-CLASSES ***************** //
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "[GradeTooHighException]() Dtor called" << std::endl;
	return ;
}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "[GradeTooLowException]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
Bureaucrat					&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "[Bureaucrat]= Overload called" << std::endl;
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream				&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}

// * NESTED-CLASSES ***************** //
Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=
						(GradeTooHighException const &rhs) throw()
{
	std::cout << "[GradeTooHighException]= Overload called" << std::endl;
	(void)rhs;
	return (*this);
}
Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=
						(GradeTooLowException const &rhs) throw()
{
	std::cout << "[GradeTooLowException]= Overload called" << std::endl;
	(void)rhs;
	return (*this);
}



// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
const std::string			&Bureaucrat::getName(void) const
	{return this->_name;}
int							Bureaucrat::getGrade(void) const
	{return this->_grade;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
	return ;
}

void						Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
	return ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
