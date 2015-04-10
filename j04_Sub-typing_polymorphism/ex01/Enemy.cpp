// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:13:32 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:15:10 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "Enemy.hpp"

// ************************************************************************** //
// ************************************************************* CONSTRUCTORS //
Enemy::Enemy(Enemy const & src) :
_hp(src.getHp()), _type(src.getType())
{
	std::cout << "[Enemy](src) constructor called!" << std::endl;
	return ;
}

Enemy::Enemy(int hp, std::string const &type) :
_hp(hp), _type(type)
{
	std::cout << "[Enemy](hp, type) constructor called!" << std::endl;
	return ;
}
// CONSTRUCTORS ************************************************************* //
// ************************************************************************** //
// ************************************************************** DESTRUCTORS //
Enemy::~Enemy()
{
	std::cout << "~[Enemy]() destructor called!" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************** //
// ************************************************************************** //
// **************************************************************** OPERATORS //
Enemy				&Enemy::operator=(Enemy const &rhs)
{
	std::cout << "[Enemy]= called!" << std::endl;
	this->_hp = rhs.getHp();
	this->_type = rhs.getType();
	return (*this);
}
// ****************************************************************** GETTERS //
std::string	const	&Enemy::getType(void) const{return (this->_type);}
int					Enemy::getHp(void) const{return (this->_hp);}
// GETTERS ****************************************************************** //
// ************************************************************************** //
// ****************************************************************** SETTERS //
// SETTERS ****************************************************************** //
// ************************************************************************** //
void				Enemy::takeDamage(int amount)
{
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
	return ;
}
 
