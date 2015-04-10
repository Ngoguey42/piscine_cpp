// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:08:27 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:12:36 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "PowerFist.hpp"

// ************************************************************************** //
// ****************************************************************** STATICS //
std::string const		PowerFist::_defaultName = "Power Fist";
int const				PowerFist::_defaultDamage = 50;
int const				PowerFist::_defaultAPCost = 8;
std::string const		PowerFist::_defaultMsg = "* pschhh... SBAM! *";
// STATICS ****************************************************************** //
// ************************************************************************** //
// ************************************************************* CONSTRUCTORS //

PowerFist::PowerFist() :
AWeapon(PowerFist::_defaultName, PowerFist::_defaultAPCost,
	PowerFist::_defaultDamage)
{
	std::cout << "[PowerFist]() constructor called!" << std::endl;
	this->_msg = PowerFist::_defaultMsg;
	return ;
}

PowerFist::PowerFist(PowerFist const &src) :
AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	std::cout << "[PowerFist](src) constructor called!" << std::endl;
	this->_msg = src.getMsg();
	return ;
}

// CONSTRUCTORS ************************************************************* //
// ************************************************************************** //
// ************************************************************** DESTRUCTORS //
PowerFist::~PowerFist()
{
	std::cout << "~[PowerFist]() destructor called!" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************** //
// ************************************************************************** //
// **************************************************************** OPERATORS //
PowerFist				&PowerFist::operator=(PowerFist const &rhs)
{
	std::cout << "[PowerFist]= called!" << std::endl;
	AWeapon::operator = (rhs);
	return (*this);
}
// std::ostream		&operator<<(std::ostream & o, PowerFist const & rhs)
// {
	// o << "" << std::endl;
	// return (o);
// }
// OPERATORS **************************************************************** //
// ************************************************************************** //
// ****************************************************************** GETTERS //
// GETTERS ****************************************************************** //
// ************************************************************************** //
// ****************************************************************** SETTERS //
// SETTERS ****************************************************************** //
// ************************************************************************** //
void					PowerFist::attack(void) const
{
	std::cout << this->getMsg() << std::endl;
	return ;
}
