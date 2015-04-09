// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 11:27:34 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 12:37:30 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "ScavTrap.hpp"

ScavTrap::clg		ScavTrap::clg_tab[4] =
{
	&ScavTrap::clg_comeback,
	&ScavTrap::clg_chicken,
	&ScavTrap::clg_pansy,
	&ScavTrap::clg_com
};

// ************************************************************ CONSTRUCTORS //
ScavTrap::ScavTrap() :
	ClapTrap()
{
	std::cout << "Constructor called, Scav operational." <<
		std::endl;
	this->loadDefaultStats();
	return ;
}

ScavTrap::ScavTrap(std::string const &name) :
	ClapTrap(name)
{
	std::cout << "Constructor(name) called, Scav ready to fight!" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) :
	ClapTrap(src)	
{
	std::cout << "Constructor(copy) called, Scav ready to guard!" <<
		std::endl;
	return ;
}
// ************************************************************* DESTRUCTORS //
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called, It's just a flesh wound!" << std::endl;
	return ;
}
// *************************************************************** OPERATORS //
ScavTrap			&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "= overload called (scav)" << std::endl;
	ClapTrap::operator = (rhs);
	// this->_hp = rhs.getHp();
	// this->_hpMax = rhs.getHpMax();
	// this->_mana = rhs.getMana();
	// this->_manaMax = rhs.getManaMax();
	// this->_level = rhs.getLevel();
	// this->_meleeDamage = rhs.getMeleeDamage();
	// this->_rangedDamage = rhs.getRangedDamage();
	// this->_armorReduction = rhs.getArmorReduction();
	return (*this);
}
// ***************************************************************** GETTERS //
// ***************************************************************** SETTERS //
void				ScavTrap::challengeNewcomer(std::string const &target)
{
	(this->*ScavTrap::clg_tab[rand() % 4])(target);
	return ;
}
void				ScavTrap::clg_com(std::string const &target) const
{
	std::cout << "<SC4V-TP>"<< this->_name << ": Come 'ere " << target <<
		"!" << std::endl;
	return ;
}
void				ScavTrap::clg_pansy(std::string const &target) const
{
	std::cout << "<SC4V-TP>"<< this->_name << ": Come on " << target <<
		" you pansy!" << std::endl;
	return ;
}
void				ScavTrap::clg_chicken(std::string const &target) const
{
	std::cout << "<SC4V-TP>"<< this->_name << ": Chicken! " << target <<
	" Chicken!" << std::endl;
	return ;
}
void				ScavTrap::clg_comeback(std::string const &target) const
{
	std::cout << "<SC4V-TP>"<< this->_name << ": Come back here " << target <<
		" and take what's coming to you." << std::endl;
	return ;
}
void				ScavTrap::loadDefaultStats(void)
{
	this->_hp = 100;
	this->_hpMax = 100;
	this->_mana = 50;
	this->_manaMax = 50;
	this->_level = 1;
	this->_meleeDamage = 20;
	this->_rangedDamage = 15;
	this->_armorReduction = 3;
	this->_class = "SC4V";
	return ;
}
