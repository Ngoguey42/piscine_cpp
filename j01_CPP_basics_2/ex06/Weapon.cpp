// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 14:18:33 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 14:21:13 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) :
	_type(type)
{
	std::cout << "Weapon constructed" << std::endl;
	return ;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructed" << std::endl;
	return ;
}

void				Weapon::setType(std::string const &type)
{
	this->_type = type;
	return ;
}

std::string const	&Weapon::getType(void) const
{
	return (this->_type);
}
