
#include <iostream>
#include <cstdlib>
#include "FragTrap.hpp"

// ************************************************************************* //
// ************************************************************ CONSTRUCTORS //

static void			fill_func_tab(vh_attack attacks[5])
{
	attacks[0] = &FragTrap::vh_funzerker; 
	attacks[1] = &FragTrap::vh_laserInferno; 
	attacks[2] = &FragTrap::vh_miniontrap; 
	attacks[3] = &FragTrap::vh_oneShotWonder; 
	attacks[4] = &FragTrap::vh_torgueFiesta; 
	return ;
}

FragTrap::FragTrap() :
	ClapTrap("Unknown_fragTrap")
{
	std::cout << "Constructor called, Let's get this party started!" <<
		std::endl;
	fill_func_tab(this->vaulthunter_attacks);
	return ;
}

FragTrap::FragTrap(std::string const name) :
	ClapTrap(name)
{
	std::cout << "Constructor(name) called, Recompiling my combat code!" <<
		std::endl;
	fill_func_tab(this->vaulthunter_attacks);
	return ;
}

FragTrap::FragTrap(FragTrap const & src) :
	ClapTrap(src)
{
	std::cout << "Constructor(copy) called, Check out my package!" <<
		std::endl;
	fill_func_tab(this->vaulthunter_attacks);
	return ;
}
// CONSTRUCTORS ************************************************************ //
// ************************************************************************* //
// ************************************************************* DESTRUCTORS //
FragTrap::~FragTrap()
{
	std::cout << "Destructor called, That looks like it hurt!" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************* //
// ************************************************************************* //
// *************************************************************** OPERATORS //
// OPERATORS *************************************************************** //
// ************************************************************************* //
// ***************************************************************** GETTERS //
// GETTERS ***************************************************************** //
// ************************************************************************* //
// ***************************************************************** SETTERS //
// SETTERS ***************************************************************** //
// ************************************************************************* //
void				FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->_mana < 25)
	{
		std::cout << "<FR4G-TP>"<< this->name << " doesn't have enough energy!"
			<< std::endl;
		return ;
	}
	this->_mana -= 25;
	(this->*vaulthunter_attacks[rand() % 5])(target);
	return ;
}
void				FragTrap::vh_funzerker(std::string const &target)
{
	std::cout << "<FR4G-TP>"<< this->name << " uses Funzerker on " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::vh_laserInferno(std::string const &target)
{
	std::cout << "<FR4G-TP>"<< this->name << " uses Laser Inferno on " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::vh_miniontrap(std::string const &target)
{
	std::cout << "<FR4G-TP>"<< this->name << " uses Miniontrap on " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::vh_oneShotWonder(std::string const &target)
{
	std::cout << "<FR4G-TP>"<< this->name << " uses One Shot Wonder on " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
void				FragTrap::vh_torgueFiesta(std::string const &target)
{
	std::cout << "<FR4G-TP>"<< this->name << " uses Torgue Fiesta on " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
