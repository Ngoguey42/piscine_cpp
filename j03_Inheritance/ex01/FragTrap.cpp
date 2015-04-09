// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 08:57:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 16:20:53 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "FragTrap.hpp"

FragTrap::vh			FragTrap::vh_tab[5] =
{
	&FragTrap::vh_funzerker,
	&FragTrap::vh_laserInferno,
	&FragTrap::vh_miniontrap,
	&FragTrap::vh_oneShotWonder,
	&FragTrap::vh_torgueFiesta
};

// ************************************************************ CONSTRUCTORS //
FragTrap::FragTrap() :
	_name("Unknown"), _hp(100), _hpMax(100), _mana(100), _manaMax(100), _level(1),
	_meleeDamage(30), _rangedDamage(20), _armorReduction(5)
{
	std::cout << "Constructor called, Let's get this party started!" <<
		std::endl;
	return ;
}

FragTrap::FragTrap(std::string const &name) :
	_name(name), _hp(100), _hpMax(100), _mana(100), _manaMax(100), _level(1),
	_meleeDamage(30), _rangedDamage(20), _armorReduction(5)
{
	std::cout << "Constructor(name) called, Recompiling my combat code!" <<
		std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) :
	_name(src._name), _hp(src._hp), _hpMax(src._hpMax),
	_mana(src._mana), _manaMax(src._manaMax), _level(src._level),
	_meleeDamage(src._meleeDamage), _rangedDamage(src._rangedDamage),
	_armorReduction(src._armorReduction)
{
	std::cout << "Constructor(copy) called, Check out my package!" <<
		std::endl;
	return ;
}
// ************************************************************* DESTRUCTORS //
FragTrap::~FragTrap()
{
	std::cout << "Destructor called, That looks like it hurt!" << std::endl;
	return ;
}
// *************************************************************** OPERATORS //
FragTrap			&FragTrap::operator=(FragTrap const &rhs)
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
// ***************************************************************** GETTERS //
std::string const	&FragTrap::getName(void) const
{return (this->_name);}
unsigned int		FragTrap::getHpMax(void) const
{return (this->_hpMax);}
unsigned int		FragTrap::getHp(void) const
{return (this->_hp);}
unsigned int		FragTrap::getMana(void) const
{return (this->_mana);}
unsigned int		FragTrap::getManaMax(void) const
{return (this->_manaMax);}
unsigned int		FragTrap::getLevel(void) const
{return (this->_level);}
unsigned int		FragTrap::getMeleeDamage(void) const
{return (this->_meleeDamage);}
unsigned int		FragTrap::getRangedDamage(void) const
{return (this->_rangedDamage);}
unsigned int		FragTrap::getArmorReduction(void) const
{return (this->_armorReduction);}
// ***************************************************************** SETTERS //
void				FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " ranged attacks " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " melee attacks " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "<FR4G-TP>"<< this->_name;
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
void				FragTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	if (this->_hp > this->_hpMax)
		this->_hp = this->_hpMax;
	std::cout << "<FR4G-TP>"<< this->_name << " gains " << amount <<
		" health points!" << "(" << this->_hp << "/" << this->_hpMax <<
		")" << std::endl;
	return ;
}

void				FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->_mana < 25)
	{
		std::cout << "<FR4G-TP>"<< this->_name << " doesn't have enough energy!"
				  << std::endl;
		return ;
	}
	this->_mana -= 25;
	(this->*FragTrap::vh_tab[rand() % 5])(target);
	return ;
}
void				FragTrap::vh_funzerker(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " uses Funzerker on " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::vh_laserInferno(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " uses Laser Inferno on " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::vh_miniontrap(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " uses Miniontrap on " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::vh_oneShotWonder(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " uses One Shot Wonder on " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::vh_torgueFiesta(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " uses Torgue Fiesta on " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
