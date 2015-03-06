

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string const name);
	~HumanB();
	void				setWeapon(Weapon &weapon);
	void				attack(void) const;
private:
	std::string const	_name;
	Weapon 				*_weapon;
};

#endif
