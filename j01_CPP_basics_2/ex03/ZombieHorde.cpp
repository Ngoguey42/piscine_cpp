// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:45:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/08 08:52:02 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(int len)
{
	this->_len = len;
	this->_zombies = new Zombie[len];
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_zombies;
	return ;
}

void		ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_len; i++)
		this->_zombies[i].announce();
	return ;
}

