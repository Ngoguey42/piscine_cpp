
#include <iostream>
#include <cstdlib>
#include "ScavTrap.hpp"

// ************************************************************************* //
// ************************************************************ CONSTRUCTORS //

static void			fill_func_tab(clg_attack attacks[4])
{
	attacks[0] = &ScavTrap::clg_comeback; 
	attacks[1] = &ScavTrap::clg_chicken; 
	attacks[2] = &ScavTrap::clg_pansy; 
	attacks[3] = &ScavTrap::clg_com; 
	return ;
}

ScavTrap::ScavTrap() :
name("Unknown"), _hp(100), _hpMax(100), _mana(50), _manaMax(50), _level(1),
_meleeDamage(20), _rangedDamage(15), _armorReduction(3)
{
	std::cout << "Constructor called, Scav operational." <<
		std::endl;
	fill_func_tab(this->challenges);
	return ;
}

ScavTrap::ScavTrap(std::string const name) :
name(name), _hp(100), _hpMax(100), _mana(50), _manaMax(50), _level(1),
_meleeDamage(20), _rangedDamage(15), _armorReduction(3)
{
	std::cout << "Constructor(name) called, Scav ready to fight!" <<
		std::endl;
	fill_func_tab(this->challenges);
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) :
name(src.name), _hp(100), _hpMax(100), _mana(50), _manaMax(50), _level(1),
_meleeDamage(20), _rangedDamage(15), _armorReduction(3)
{
	std::cout << "Constructor(copy) called, Scav ready to guard!" <<
		std::endl;
	fill_func_tab(this->challenges);
	return ;
}
// CONSTRUCTORS ************************************************************ //
// ************************************************************************* //
// ************************************************************* DESTRUCTORS //
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called, It's just a flesh wound!" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************* //
// ************************************************************************* //
// *************************************************************** OPERATORS //
ScavTrap			&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "= overload called (scav)" << std::endl;
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
std::string			ScavTrap::getName(void) const
{return (this->name);}
unsigned int		ScavTrap::getHpMax(void) const
{return (this->_hpMax);}
unsigned int		ScavTrap::getHp(void) const
{return (this->_hp);}
unsigned int		ScavTrap::getMana(void) const
{return (this->_mana);}
unsigned int		ScavTrap::getManaMax(void) const
{return (this->_manaMax);}
unsigned int		ScavTrap::getLevel(void) const
{return (this->_level);}
unsigned int		ScavTrap::getMeleeDamage(void) const
{return (this->_meleeDamage);}
unsigned int		ScavTrap::getRangedDamage(void) const
{return (this->_rangedDamage);}
unsigned int		ScavTrap::getArmorReduction(void) const
{return (this->_armorReduction);}
// GETTERS ***************************************************************** //
// ************************************************************************* //
// ***************************************************************** SETTERS //
// SETTERS ***************************************************************** //
// ************************************************************************* //
void				ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "<SC4V-TP>"<< this->name << " ranged attacks " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
void				ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "<SC4V-TP>"<< this->name << " melee attacks " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}
void				ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "<SC4V-TP>"<< this->name;
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
void				ScavTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	if (this->_hp > this->_hpMax)
		this->_hp = this->_hpMax;
	std::cout << "<SC4V-TP>"<< this->name << " gains " << amount <<
		" health points!" << "(" << this->_hp << "/" << this->_hpMax <<
		")" << std::endl;
	return ;
}

void				ScavTrap::challengeNewcomer(std::string const &target)
{
	(this->*challenges[rand() % 4])(target);
	return ;
}
void				ScavTrap::clg_com(std::string const &target)
{
	std::cout << "<SC4V-TP>"<< this->name << ": Come 'ere " << target <<
		"!" << std::endl;
	return ;
}
void				ScavTrap::clg_pansy(std::string const &target)
{
	std::cout << "<SC4V-TP>"<< this->name << ": Come on " << target <<
		" you pansy!" << std::endl;
	return ;
}
void				ScavTrap::clg_chicken(std::string const &target)
{
	std::cout << "<SC4V-TP>"<< this->name << ": Chicken! " << target <<
	" Chicken!" << std::endl;
	return ;
}
void				ScavTrap::clg_comeback(std::string const &target)
{
	std::cout << "<SC4V-TP>"<< this->name << ": Come back here " << target <<
		" and take what's coming to you." << std::endl;
	return ;
}