
#include <iostream>
#include <cstdlib>
#include "AWeapon.hpp"

// ************************************************************************** //
// ************************************************************* CONSTRUCTORS //

AWeapon::AWeapon() :
_name("NoName"), _damage(0), _aPCost(1), _msg("No msg.")
{
	std::cout << "[AWeapon]() constructor called!" << std::endl;
	return ;
}

AWeapon::AWeapon(AWeapon const & src) :
_name(src.getName()), _damage(src.getDamage()), _aPCost(src.getAPCost()),
_msg(src.getMsg())
{
	std::cout << "[AWeapon](src) constructor called!" << std::endl;
	return ;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) :
_name(name), _damage(damage), _aPCost(apcost), _msg("No msg.")
{
	std::cout << "[AWeapon](hp, type) constructor called!" << std::endl;
	return ;
}
// CONSTRUCTORS ************************************************************* //
// ************************************************************************** //
// ************************************************************** DESTRUCTORS //
AWeapon::~AWeapon()
{
	std::cout << "~[AWeapon]() destructor called!" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************** //
// ************************************************************************** //
// **************************************************************** OPERATORS //
AWeapon				&AWeapon::operator=(AWeapon const &rhs)
{
	std::cout << "[AWeapon]= called!" << std::endl;
	this->_aPCost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	this->_name = rhs.getName();
	this->_msg = rhs.getMsg();
	return (*this);
}
// std::ostream		&operator<<(std::ostream & o, AWeapon const & rhs)
// {
	// o << "" << std::endl;
	// return (o);
// }
// OPERATORS **************************************************************** //
// ************************************************************************** //
// ****************************************************************** GETTERS //
int					AWeapon::getAPCost(void) const
{return (this->_aPCost);}
int					AWeapon::getDamage(void) const
{return (this->_damage);}
std::string	const	&AWeapon::getName(void) const
{return (this->_name);}
std::string	const	&AWeapon::getMsg(void) const
{return (this->_msg);}
// GETTERS ****************************************************************** //
// ************************************************************************** //
// ****************************************************************** SETTERS //
// SETTERS ****************************************************************** //
// ************************************************************************** //
