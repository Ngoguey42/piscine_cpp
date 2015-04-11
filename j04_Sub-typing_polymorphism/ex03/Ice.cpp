// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ice.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:52:52 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 13:09:27 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ice.hpp"

// * STATICS **************************************************************** //
std::string const			Ice::_useMsg1 = "* shoots an ice bolt at ";
std::string const			Ice::_useMsg2 = " *";
std::string const			Ice::_name = "ice";

// * CONSTRUCTORS *********************************************************** //
Ice::Ice() :
	AMateria(Ice::_name)
{
	std::cout << "[Ice]() Ctor called" << std::endl;
	return ;
}
Ice::Ice(Ice const &src) :
	AMateria(src)
{
	std::cout << "[Ice](Ice const&) Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Ice::~Ice()
{
	std::cout << "[Ice]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
Ice							&Ice::operator=(Ice const &rhs)
{
	std::cout << "[Ice]operator=" << std::endl;
	AMateria::operator = (rhs);
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
AMateria					*Ice::clone() const
{
	return (new Ice(*this));
}
void						Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << Ice::_useMsg1 << this->_name << Ice::_useMsg2 << std::endl;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
