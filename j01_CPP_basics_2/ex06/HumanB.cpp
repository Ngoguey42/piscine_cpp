

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL)
{
	std::cout << "HumanB constructed" << std::endl;
	return ;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructed" << std::endl;
	return ;
}

void				HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
void				HumanB::attack(void) const
{
	if (this->_weapon != NULL)
	{
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	}
	else
		std::cout << "No weapon equipped!" << std::endl;
	return ;
}
