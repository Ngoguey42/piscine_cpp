// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 14:22:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 14:26:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string const &name);
	~HumanB();
	void				setWeapon(Weapon &weapon);
	void				attack(void) const;
private:
	std::string const	_name;
	Weapon 				*_weapon;
};

#endif
