
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
	ClapTrap("Unknown_scavTrap")
{
	std::cout << "Constructor called, Scav operational." <<
		std::endl;
	fill_func_tab(this->challenges);
	return ;
}

ScavTrap::ScavTrap(std::string const name) :
	ClapTrap(name)
{
	std::cout << "Constructor(name) called, Scav ready to fight!" <<
		std::endl;
	fill_func_tab(this->challenges);
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) :
	ClapTrap(src)
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
// OPERATORS *************************************************************** //
// ************************************************************************* //
// ***************************************************************** GETTERS //
// GETTERS ***************************************************************** //
// ************************************************************************* //
// ***************************************************************** SETTERS //
// SETTERS ***************************************************************** //
// ************************************************************************* //
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
