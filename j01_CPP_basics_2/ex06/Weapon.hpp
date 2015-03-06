

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <iostream>
# include "Weapon.hpp"

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon();
	void				setType(std::string type);
	std::string const	getType(void) const;
private:
	std::string			_type;
};

#endif
