// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 12:38:12 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 12:40:36 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

// ************************************************************************* //
// ************************************************************ CONSTRUCTORS //

ClapTrap::ClapTrap() :
_name("Unknown"), _hp(100), _hpMax(100), _mana(100), _manaMax(100), _level(1),
_meleeDamage(30), _rangedDamage(20), _armorReduction(5), _class("CL4P")
{
	std::cout << "ClapTrap() constructor called!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string const &name) :
_name(name), _hp(100), _hpMax(100), _mana(100), _manaMax(100), _level(1),
_meleeDamage(30), _rangedDamage(20), _armorReduction(5), _class("CL4P")
{
	std::cout << "ClapTrap(name) constructor called!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) :
_name(src._name), _hp(100), _hpMax(100), _mana(100), _manaMax(100), _level(1),
_meleeDamage(30), _rangedDamage(20), _armorReduction(5), _class("CL4P")
{
	std::cout << "ClapTrap(src) constructor called!" << std::endl;
	return ;
}
// CONSTRUCTORS ************************************************************ //
// ************************************************************************* //
// ************************************************************* DESTRUCTORS //
ClapTrap::~ClapTrap()
{
	std::cout << "~ClapTrap() destructor called!" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************* //
// ************************************************************************* //
// *************************************************************** OPERATORS //
ClapTrap			&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "= overload called" << std::endl;
	this->_hp = rhs.getHp();
	this->_hpMax = rhs.getHpMax();
	this->_mana = rhs.getMana();
	this->_manaMax = rhs.getManaMax();
	this->_level = rhs.getLevel();
	this->_meleeDamage = rhs.getMeleeDamage();
	this->_rangedDamage = rhs.getRangedDamage();
	this->_armorReduction = rhs.getArmorReduction();
	return (*this);
}
// OPERATORS *************************************************************** //
// ************************************************************************* //
// ***************************************************************** GETTERS //
std::string const	&ClapTrap::getName(void) const
{return (this->_name);}
unsigned int		ClapTrap::getHpMax(void) const
{return (this->_hpMax);}
unsigned int		ClapTrap::getHp(void) const
{return (this->_hp);}
unsigned int		ClapTrap::getMana(void) const
{return (this->_mana);}
unsigned int		ClapTrap::getManaMax(void) const
{return (this->_manaMax);}
unsigned int		ClapTrap::getLevel(void) const
{return (this->_level);}
unsigned int		ClapTrap::getMeleeDamage(void) const
{return (this->_meleeDamage);}
unsigned int		ClapTrap::getRangedDamage(void) const
{return (this->_rangedDamage);}
unsigned int		ClapTrap::getArmorReduction(void) const
{return (this->_armorReduction);}
// GETTERS ***************************************************************** //
// ************************************************************************* //
// ***************************************************************** SETTERS //
// SETTERS ***************************************************************** //
// ************************************************************************* //
void				ClapTrap::rangedAttack(std::string const &target) const
{
	std::cout << "<" << this->_class << "-TP>" << this->_name <<
		" ranged attacks " << target << ", for " << this->_rangedDamage <<
		" damages!" << std::endl;
	(void)target;
}
void				ClapTrap::meleeAttack(std::string const &target) const
{
	std::cout << "<" << this->_class << "-TP>" << this->_name <<
		" melee attacks " << target << ", for " << this->_meleeDamage <<
		" damages!" << std::endl;
	return ;
}
void				ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "<" << this->_class << "-TP>" << this->_name;
	if (amount <= this->_armorReduction)
		std::cout << " resists ";
	else
	{
		amount -= this->_armorReduction;
		std::cout << " takes " << amount << " damages ";
		if (amount >= this->_hp)
			this->_hp = 0;
		else
			this->_hp -= amount;
	}
	std::cout << "(" << this->_hp << "/" << this->_hpMax << ")" << std::endl;
	return ;
}
void				ClapTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	if (this->_hp > this->_hpMax)
		this->_hp = this->_hpMax;
	std::cout << "<" << this->_class << "-TP>" << this->_name << " gains " <<
		amount << " health points!" << "(" << this->_hp << "/" <<
		this->_hpMax << ")" << std::endl;
	return ;
}
