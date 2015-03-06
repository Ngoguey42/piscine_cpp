

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string const name, Weapon weapon);
	// HumanA(std::string const name);
	~HumanA();
	// void				setWeapon(Weapon &weapon);
	void				attack(void) const;
private:
	std::string const	_name;
	Weapon 				_weapon;
};

#endif
