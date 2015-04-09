// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 08:57:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 16:01:57 by ngoguey          ###   ########.fr       //
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
	ClapTrap()
{
	std::cout << "Frag Constructor called, Let's get this party started!" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}
FragTrap::FragTrap(bool) :
	ClapTrap()
{
	std::cout << "Frag Constructor(bool) called, Check out my package!" <<
		std::endl;
	this->_hp = 100;
	this->_hpMax = 100;
	this->_rangedDamage = 20;
	this->_armorReduction = 5;
	return ;
}
FragTrap::FragTrap(std::string const &name) :
	ClapTrap(name)
{
	std::cout << "Frag Constructor(name) called, Recompiling my combat code!" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}
FragTrap::FragTrap(FragTrap const &src) :
	ClapTrap(static_cast<ClapTrap const &>(src))
{
	std::cout << "Frag Constructor(copy) called, Check out my package!" <<
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
// ***************************************************************** SETTERS //
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

void                FragTrap::loadDefaultStats(void)
{
	this->_hp = 100;
	this->_hpMax = 100;
	this->_mana = 100;
	this->_manaMax = 100;
	this->_level = 1;
	this->_meleeDamage = 30;
	this->_rangedDamage = 20;
	this->_armorReduction = 5;
	this->_class = "FR4G";
	return ;
}
void                FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "Frag's trap rangedAttack called" << std::endl;
	ClapTrap::rangedAttack(target);
	return ;
}
