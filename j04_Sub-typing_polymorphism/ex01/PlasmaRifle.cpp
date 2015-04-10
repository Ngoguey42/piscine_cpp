// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:11:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:19:21 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "PlasmaRifle.hpp"

// ************************************************************************** //
// ****************************************************************** STATICS //
std::string const		PlasmaRifle::_defaultName = "Plasma Rifle";
int const				PlasmaRifle::_defaultDamage = 21;
int const				PlasmaRifle::_defaultAPCost = 5;
std::string const		PlasmaRifle::_defaultMsg = "* piouuu piouuu piouuu *";
// STATICS ****************************************************************** //
// ************************************************************************** //
// ************************************************************* CONSTRUCTORS //

PlasmaRifle::PlasmaRifle() :
AWeapon(PlasmaRifle::_defaultName, PlasmaRifle::_defaultAPCost,
	PlasmaRifle::_defaultDamage)
{
	std::cout << "[PlasmaRifle]() constructor called!" << std::endl;
	this->_msg = PlasmaRifle::_defaultMsg;
	return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) :
AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	std::cout << "[PlasmaRifle](src) constructor called!" << std::endl;
	this->_msg = src.getMsg();
	return ;
}

// CONSTRUCTORS ************************************************************* //
// ************************************************************************** //
// ************************************************************** DESTRUCTORS //
PlasmaRifle::~PlasmaRifle()
{
	std::cout << "~[PlasmaRifle]() destructor called!" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************** //
// ************************************************************************** //
// **************************************************************** OPERATORS //
PlasmaRifle				&PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	std::cout << "[PlasmaRifle]= called!" << std::endl;
	AWeapon::operator = (rhs);
	return (*this);
}
// std::ostream		&operator<<(std::ostream & o, PlasmaRifle const & rhs)
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
void					PlasmaRifle::attack(void) const
{
	std::cout << this->getMsg() << std::endl;
	return ;
}
