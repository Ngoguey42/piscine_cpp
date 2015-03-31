// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 10:50:43 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 15:06:30 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"

// **************************************************** STATICS *** STATICS * //
const int					Bureaucrat::highestGrade = 1;
const int					Bureaucrat::lowestGrade = 150;
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Bureaucrat::Bureaucrat(std::string const &name, int startGrade)
	throw(GradeTooHighException, GradeTooLowException) :
	_name(name), _grade(startGrade)
{
	std::cout << "[Bureaucrat](main) Ctor called" << std::endl;
	if (startGrade < Bureaucrat::highestGrade)
		throw GradeTooHighException();
	if (startGrade > Bureaucrat::lowestGrade)
		throw GradeTooLowException();
	return ;
}

// * NESTED-CLASSES ***************** //
Bureaucrat::GradeTooHighException::GradeTooHighException() :
	std::exception()
{
	std::cout << "[GradeTooHighException]() Ctor called" << std::endl;
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() :
	std::exception()
{
	std::cout << "[GradeTooLowException]() Ctor called" << std::endl;
	return ;
}
Bureaucrat::GradeTooHighException::GradeTooHighException(
	GradeTooHighException const &rhs) : std::exception()
{
	std::cout << "[GradeTooHighException](cpy) Ctor called" << std::endl;
	(void)rhs;
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
	GradeTooLowException const &rhs) : std::exception()
{
	std::cout << "[GradeTooLowException](cpy) Ctor called" << std::endl;
	(void)rhs;
	return ;
}

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

// ************************************************ OPERATORS *** OPERATORS * //
std::ostream				&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}

// **************************************************** GETTERS *** GETTERS * //
const std::string			&Bureaucrat::getName(void) const
{return this->_name;}
int							Bureaucrat::getGrade(void) const
{return this->_grade;}

void						Bureaucrat::incrementGrade(void)
	throw(GradeTooHighException)
{
	if (this->_grade - 1 < Bureaucrat::highestGrade)
		throw GradeTooHighException();
	this->_grade -= 1;
	return ;
}

void						Bureaucrat::decrementGrade(void)
	throw(GradeTooLowException)
{
	if (this->_grade + 1 > Bureaucrat::lowestGrade)
		throw GradeTooLowException();
	this->_grade += 1;
	return ;
}
void						Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " cannot sign " << f.getName() <<
			" because " << e.what() << std::endl;
	}
	return ;
}
void						Bureaucrat::executeForm(Form const &f)
{
	try
	{
		std::cout << this->_name << " executes " << f.getName() << " on " <<
			f.getTarget() << std::endl;
		f.tryExecute(*this);		
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " cannot execute " << f.getName() <<
			" because " << e.what() << std::endl;
	}
	catch (Form::FormNotSignedException &e)
	{
		std::cout << this->_name << " cannot execute " << f.getName() <<
			" because " << e.what() << std::endl;
	}
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
