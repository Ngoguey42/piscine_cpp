
#include <iostream>
#include <cstdlib>
#include "Peon.hpp"

// ************************************************************************* //
// ************************************************************ CONSTRUCTORS //

Peon::Peon() :
Victim()
{
	std::cout << "[Peon]() constructor called!" << std::endl;
	return ;
}

Peon::Peon(Peon const & src) :
Victim(src.getName())
{
	std::cout << "[Peon](src) constructor called!" << std::endl;
	return ;
}

Peon::Peon(std::string const name) :
Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return ;
}
// CONSTRUCTORS ************************************************************ //
// ************************************************************************* //
// ************************************************************* DESTRUCTORS //
Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************* //
// ************************************************************************* //
// *************************************************************** OPERATORS //
Peon			&Peon::operator=(Peon const &rhs)
{
	std::cout << "[Peon]= called!" << std::endl;
	this->_name = rhs.getName();
	return (*this);
}
std::ostream		&operator<<(std::ostream & o, Peon const & rhs)
{
	o << "I'm " << rhs.getName() << " and i like otters !" << std::endl;
	return (o);
}
// OPERATORS *************************************************************** //
// ************************************************************************* //
// ***************************************************************** GETTERS //
// GETTERS ***************************************************************** //
// ************************************************************************* //
// ***************************************************************** SETTERS //
// SETTERS ***************************************************************** //
// ************************************************************************* //
void				Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a pink pony !" <<
		std::endl;
	return ;
}
