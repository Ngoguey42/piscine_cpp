
#include <iostream>
#include <cstdlib>
#include "RadScorpion.hpp"

// ************************************************************************** //
// ****************************************************************** STATICS //
std::string const	&RadScorpion::_typeName = "RadScorpion";
int const			RadScorpion::_baseHp = 80;
std::string const	&RadScorpion::_birthMsg = "* click click click *";
std::string const	&RadScorpion::_deathMsg = "* SPROTCH *";
// STATICS ****************************************************************** //
// ************************************************************************** //
// ************************************************************* CONSTRUCTORS //

RadScorpion::RadScorpion() :
Enemy(RadScorpion::_baseHp, RadScorpion::_typeName)
{
	std::cout << RadScorpion::_birthMsg << std::endl;
	return ;
}

RadScorpion::RadScorpion(RadScorpion const & src) :
Enemy(src.getHp(), src.getType())
{
	std::cout << "[RadScorpion](src) constructor called!" << std::endl;
	return ;
}
// CONSTRUCTORS ************************************************************* //
// ************************************************************************** //
// ************************************************************** DESTRUCTORS //
RadScorpion::~RadScorpion()
{
	std::cout << RadScorpion::_deathMsg << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************** //
// ************************************************************************** //
// **************************************************************** OPERATORS //
RadScorpion		&RadScorpion::operator=(RadScorpion const &rhs)
{
	std::cout << "[RadScorpion]= called!" << std::endl;
	this->_hp = rhs.getHp();
	this->_type = rhs.getType();
	return (*this);
}
// std::ostream		&operator<<(std::ostream & o, RadScorpion const & rhs)
// {
	// o << "" << std::endl;
	// return (o);
// }
// OPERATORS **************************************************************** //
// ************************************************************************** //
// ****************************************************************** GETTERS //
// GETTERS ****************************************************************** //
// ************************************************************************** //
// ****************************************************************** SETTERS //
// SETTERS ****************************************************************** //
// ************************************************************************** //