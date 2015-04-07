// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 12:54:39 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:32:53 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent(void)
{
	this->_curType = "None";
	return ;
}

ZombieEvent::~ZombieEvent(void){return ;}

void		ZombieEvent::setZombieType(std::string const &type)
{
	this->_curType = type;
	return ;
}

Zombie		*ZombieEvent::newZombie(std::string const &name)
{
	for (size_t i = 0; i < sizeof(Zombie::types) /
			 sizeof(*Zombie::types); i++)
	{
		if (this->_curType == Zombie::types[i])
			return (new Zombie(name, this->_curType));
	}
	std::cout << this->_curType << ": wrong zombie type..." << std::endl;
	return (NULL);
}

static void	chump(std::string const &type)
{
	Zombie		z(
		Zombie::default_names[(std::rand()) %
							  (sizeof(Zombie::default_names) /
							   sizeof(*Zombie::default_names))], 
		type
		);
	z.announce();
	return ;
}

void		ZombieEvent::randomChump(void) const
{
	for (size_t i = 0; i < sizeof(Zombie::types) /
			 sizeof(*Zombie::types); i++)
	{
		if (this->_curType == Zombie::types[i])
		{
			chump(this->_curType);
			return ;
		}
	}
	std::cout << this->_curType << ": wrong zombie type..." << std::endl;
	return ;
}
