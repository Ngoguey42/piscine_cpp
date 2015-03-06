

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string const name, Weapon weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA constructed" << std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructed" << std::endl;
	return ;
}

void				HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	return ;
}