// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 14:19:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 14:25:48 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon) :
	_name(name), _weapon(weapon)
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
	std::cout << this->_name << " attacks with his " <<
		this->_weapon.getType() << std::endl;
	return ;
}
