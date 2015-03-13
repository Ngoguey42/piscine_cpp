// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 16:15:54 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/13 17:21:30 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Form.hpp"

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
const int                   Form::highestGrade = 1;
const int                   Form::lowestGrade = 150;
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Form::Form(std::string const &name, int sGrade, int eGrade) :
	_name(name), _sGrade(sGrade), _eGrade(eGrade), _isSigned(false)
{
	std::cout << "[Form](main) Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Form::~Form()
{
	std::cout << "[Form]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

std::ostream				&operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form:" << rhs.getName() << " signed:" << rhs.getIsSigned();
	return (o);
}

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Form::getName(void) const{return this->_name;}
int const					Form::getSGrade(void) const{return this->_sGrade;}
int const					Form::getEGrade(void) const{return this->_eGrade;}
bool						Form::getIsSigned(void) const
	{return this->_isSigned;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
