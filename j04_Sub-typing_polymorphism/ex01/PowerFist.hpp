
#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include <iostream>
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	PowerFist(PowerFist const &rhs);
	virtual ~PowerFist();
	PowerFist					&operator=(PowerFist const &rhs);
	
	virtual void				attack(void) const;
	
protected:
	static std::string const	_defaultName;
	static int const			_defaultDamage;
	static int const			_defaultAPCost;
	static std::string const	_defaultMsg;
};

// std::ostream			&operator<<(std::ostream & o, PowerFist const & rhs);

#endif // **************************************************** POWER_FIST_HPP //
