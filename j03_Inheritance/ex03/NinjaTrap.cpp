// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 13:28:35 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 13:37:02 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "NinjaTrap.hpp"

// ************************************************************* CONSTRUCTORS //
NinjaTrap::NinjaTrap() :
	ClapTrap()
{
	std::cout << "Ninja Constructor called, How can I be of service?" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}
NinjaTrap::NinjaTrap(std::string const &name) :
	ClapTrap(name)
{
	std::cout << "Ninja Constructor(name) called, What do you need?" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}
NinjaTrap::NinjaTrap(NinjaTrap const & src) :
	ClapTrap(src)
{
	std::cout << "Ninja Constructor(copy) called, Yes captain?" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}

// ************************************************************** DESTRUCTORS //
NinjaTrap::~NinjaTrap()
{
	std::cout << "Destructor called, Arrrrrghhh" << std::endl;
	return ;
}
// *************************************************************** OPERATORS //
NinjaTrap            &NinjaTrap::operator=(NinjaTrap const &rhs)
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

void				NinjaTrap::ninjaShoebox(FragTrap &target)
{
	std::cout << "<NINJ4-TP>"<< this->_name << " steps in the shadows " <<
		"and backstabs " << target.getName() << " for " <<
		this->getMeleeDamage() + 25 << " damages." << std::endl;
	target.takeDamage(this->getMeleeDamage() + 25);
	return ;
}
void				NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	std::cout << "<NINJ4-TP>"<< this->_name << " cowers in fear seeing " <<
		target.getName() << "'s beauty." << std::endl;
	return ;
}
void				NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	std::cout << "<NINJ4-TP>"<< this->_name << " throw a nail at " <<
		target.getName() << " for " <<
		this->getRangedDamage() + 3 << " damages." << std::endl;
	target.takeDamage(this->getRangedDamage() + 3);
	return ;
}
void				NinjaTrap::loadDefaultStats(void)
{
	this->_hp = 60;
	this->_hpMax = 60;
	this->_mana = 120;
	this->_manaMax = 120;
	this->_level = 1;
	this->_meleeDamage = 60;
	this->_rangedDamage = 5;
	this->_armorReduction = 0;
	this->_class = "NINJ4";
	return ;
}
