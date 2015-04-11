// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cure.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 14:51:54 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 14:52:26 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cure.hpp"

// * STATICS **************************************************************** //
std::string const			Cure::_useMsg1 = "* heals ";
std::string const			Cure::_useMsg2 = "’s wounds *";
std::string const			Cure::_name = "cure";

// * CONSTRUCTORS *********************************************************** //
Cure::Cure() :
	AMateria(Cure::_name)
{
	std::cout << "[Cure]() Ctor called" << std::endl;
	return ;
}
Cure::Cure(Cure const &src) :
	AMateria(src)
{
	std::cout << "[Cure](Cure const&) Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Cure::~Cure()
{
	std::cout << "[Cure]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
Cure							&Cure::operator=(Cure const &rhs)
{
	std::cout << "[Cure]operator=" << std::endl;
	AMateria::operator = (rhs);
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
AMateria					*Cure::clone() const
{
	return (new Cure(*this));
}
void						Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << Cure::_useMsg1 << this->_name << Cure::_useMsg2 << std::endl;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
