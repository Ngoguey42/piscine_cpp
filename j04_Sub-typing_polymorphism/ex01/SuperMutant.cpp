// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:16:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:24:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "SuperMutant.hpp"

// ************************************************************************** //
// ****************************************************************** STATICS //
std::string const	SuperMutant::_typeName = "Super Mutant";
int const			SuperMutant::_baseHp = 170;
std::string const	SuperMutant::_birthMsg = "Gaaah. Me want smash heads !";
std::string const	SuperMutant::_deathMsg = "Aaargh ...";
// STATICS ****************************************************************** //
// ************************************************************************** //
// ************************************************************* CONSTRUCTORS //

SuperMutant::SuperMutant() :
Enemy(SuperMutant::_baseHp, SuperMutant::_typeName)
{
	std::cout << SuperMutant::_birthMsg << std::endl;
	return ;
}

SuperMutant::SuperMutant(SuperMutant const & src) :
Enemy(src.getHp(), src.getType())
{
	std::cout << "[SuperMutant](src) constructor called!" << std::endl;
	return ;
}
// CONSTRUCTORS ************************************************************* //
// ************************************************************************** //
// ************************************************************** DESTRUCTORS //
SuperMutant::~SuperMutant()
{
	std::cout << SuperMutant::_deathMsg << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************** //
// ************************************************************************** //
// **************************************************************** OPERATORS //
SuperMutant		&SuperMutant::operator=(SuperMutant const &rhs)
{
	std::cout << "[SuperMutant]= called!" << std::endl;
	Enemy::operator = (rhs);
	return (*this);
}

// ************************************************************************** //
void			SuperMutant::takeDamage(int amount)
{
	amount -= 3;
	std::cout << this->_type << " lost ";
	if (amount > 0)
	{
		std::cout << amount;
		this->_hp -= amount;
		if (this->_hp < 0)
			this->_hp = 0;
	}
	else
		std::cout << '0';
	std::cout << "hp. (" << this->_hp << ")" << std::endl;
}
 
