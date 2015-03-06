

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon constructed" << std::endl;
	return ;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructed" << std::endl;
	return ;
}

void				Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}

std::string const	Weapon::getType(void) const
{
	return (this->_type);
}
