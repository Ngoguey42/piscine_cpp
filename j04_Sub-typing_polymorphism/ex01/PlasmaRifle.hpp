// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:08:25 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:11:41 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(PlasmaRifle const &rhs);
	virtual ~PlasmaRifle();
	PlasmaRifle					&operator=(PlasmaRifle const &rhs);
	PlasmaRifle();	
	virtual void				attack(void) const;
	
protected:
	static std::string const	_defaultName;
	static int const			_defaultDamage;
	static int const			_defaultAPCost;
	static std::string const	_defaultMsg;
private:
	
};

// std::ostream			&operator<<(std::ostream & o, PlasmaRifle const & rhs);

#endif // ****************************************************** PLASMA_RIFLE_HPP //
