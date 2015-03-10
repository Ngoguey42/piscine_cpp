
#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &rhs);
	virtual ~PlasmaRifle();
	PlasmaRifle					&operator=(PlasmaRifle const &rhs);
	
	virtual void				attack(void) const;
	
protected:
	static std::string const	_defaultName;
	static int const			_defaultDamage;
	static int const			_defaultAPCost;
	static std::string const	_defaultMsg;
};

// std::ostream			&operator<<(std::ostream & o, PlasmaRifle const & rhs);

#endif // ****************************************************** PLASMA_RIFLE_HPP //
