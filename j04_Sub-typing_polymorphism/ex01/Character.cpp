// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:20:03 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:21:21 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "Character.hpp"

// ************************************************************************** //
// ****************************************************************** STATICS //
int const				Character::_defaultAPMax = 40;
int const				Character::_defaultAPRecover = 10;
// STATICS ****************************************************************** //
// ************************************************************************** //
// ************************************************************* CONSTRUCTORS //
Character::Character(std::string const &name) :
_name(name), _aP(Character::_defaultAPMax),
_aPMax(Character::_defaultAPMax), _weaponPtr(NULL)
{
	std::cout << "[Character](hp, type) constructor called!" << std::endl;
	return ;
}
// CONSTRUCTORS ************************************************************* //
// ************************************************************************** //
// ************************************************************** DESTRUCTORS //
Character::~Character()
{
	std::cout << "~[Character]() destructor called!" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************** //
// ************************************************************************** //
// **************************************************************** OPERATORS //
std::ostream		&operator<<(std::ostream &o, Character const &rhs)
{
	if (rhs.getWeapon() != NULL)
		o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " <<
			rhs.getWeapon()->getName() << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getAP() <<
			" AP and is unarmed" << std::endl;
	return (o);
}
// OPERATORS **************************************************************** //
// ************************************************************************** //
// ****************************************************************** GETTERS //
std::string	const	&Character::getName(void) const
{return (this->_name);}
int					Character::getAP(void) const
{return (this->_aP);}
int					Character::getAPMax(void) const
{return (this->_aPMax);}
const AWeapon		*Character::getWeapon(void) const
{return (this->_weaponPtr);}
// GETTERS ****************************************************************** //
// ************************************************************************** //
// ****************************************************************** SETTERS //
// SETTERS ****************************************************************** //
// ************************************************************************** //
void				Character::recoverAP(void)
{
	this->_aP += Character::_defaultAPRecover;
	if (this->_aP > this->_aPMax)
		this->_aP = this->_aPMax;
	return ;
}
void				Character::equip(AWeapon *wptr)
{
	this->_weaponPtr = wptr;
	return ;
}
void				Character::attack(Enemy *eptr)
{
	if (eptr == NULL)
		std::cout << this->_name << " doesn't have a target." << std::endl;
	else if (this->_weaponPtr == NULL)
		std::cout << this->_name << " is unarmed." << std::endl;
	else if (this->_aP < this->_weaponPtr->getAPCost())
		std::cout << this->_name << " doesn't have enough AP." << std::endl;
	else
	{
		this->_aP -= this->_weaponPtr->getAPCost();
		std::cout << this->_name << " attacks " << eptr->getType() <<
		" with a " << this->_weaponPtr->getName() << std::endl;
		this->_weaponPtr->attack();
		eptr->takeDamage(this->_weaponPtr->getDamage());
		if (eptr->getHp() <= 0)
			delete eptr;
	}
	return ;
}
