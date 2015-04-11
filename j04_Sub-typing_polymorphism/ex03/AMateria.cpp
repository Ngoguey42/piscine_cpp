// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMateria.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:43:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 13:09:14 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "AMateria.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
AMateria::AMateria(std::string const & type) :
	_XP(0),
	_name(type)
{
	std::cout << "[AMateria](std::string const &) Ctor called" << std::endl;
	(void)type;
	return ;
}
AMateria::AMateria(AMateria const &src) :
	_XP(src._XP),
	_name(src._name)
{
	std::cout << "[AMateria](AMateria const&) Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
AMateria::~AMateria()
{
	std::cout << "[AMateria]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
AMateria					&AMateria::operator=(AMateria const &rhs)
{
	std::cout << "[AMateria]operator=" << std::endl;
	this->_XP = rhs._XP;
	return (*this);
}

// * GETTERS **************************************************************** //
unsigned int				AMateria::getXP(void) const{return this->_XP;}
std::string const			&AMateria::getName(void) const{return this->_name;}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						AMateria::use(ICharacter& target)
{
	this->_XP += 10;
	(void)target;
	return ;
}


// * NESTED_CLASSES ********************************************************* //
