// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 12:52:50 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:44:50 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "[Zombie] Ctor" << std::endl;
	this->_name = Zombie::default_names[rand() % 10];
	this->_type = Zombie::types[rand() % 3];
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "[Zombie] Dtor" << std::endl;
	return ;
}

void		Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type <<
		")> Braiiiiinsss..." << std::endl;
	return ;
}

std::string	const	Zombie::types[3] = 
{
	"Boomer", "Hunter", "Witch"
};

std::string	const	Zombie::default_names[10] = 
{
	"Marco", "Polo", "Rocco", "Franco", "Macdo",
	"Waldo", "Rambo", "Pedro", "Rico", "Pecno"
};
