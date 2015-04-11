// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 13:10:42 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 15:51:10 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Character.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
Character::Character(std::string const &name) :
	_name(name),
	_nEquiped(0)
{
	std::cout << "[Character](std::string const&) Ctor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_bag[i] = NULL;
	return ;
}
Character::Character(Character const &src)
{
	std::cout << "[Character](Character const&) Ctor called" << std::endl;
	Character::operator = (src);
	return ;
}

// * DESTRUCTORS ************************************************************ //
Character::~Character()
{
	std::cout << "[Character]() Dtor called" << std::endl;
	
	return ;
}

// * OPERATORS ************************************************************** //
Character					&Character::operator=(Character const &rhs)
{
	AMateria const	*ptr;
	int				i = 0;

	this->_name = rhs.getName();
	std::cout << "[Character]operator=" << std::endl;
	this->destroyAll();
	while ((ptr = rhs.getMateria(i++)) != NULL)
		this->equip(ptr->clone());
	return (*this);
}

// * GETTERS **************************************************************** //
std::string const			&Character::getName(void) const{return this->_name;}
AMateria const              *Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= this->_nEquiped)
		return NULL;
	return (this->_bag[idx]);
}
AMateria		              *Character::getMateria(int idx)
{
	if (idx < 0 || idx >= this->_nEquiped)
		return NULL;
	return (this->_bag[idx]);
}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						Character::equip(AMateria* m)
{
	if (m == NULL || this->_nEquiped >= 3)
		return ;
	this->_bag[this->_nEquiped++] = m;
	return ;
}
void						Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_nEquiped)
		return ;
	this->_bag[idx] = NULL;
	while (++idx < this->_nEquiped)
	{
		this->_bag[idx - 1] = this->_bag[idx];
		this->_bag[idx] = NULL;
	}
	this->_nEquiped--;
	return ;
}
void						Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->_nEquiped)
		return ;
	this->_bag[idx]->use(target);
	return ;
}
void						Character::destroyAll(void)
{
	for (int i = 0; i < this->_nEquiped; i++)
	{
		delete this->_bag[i];
		this->_bag[i] = NULL;
	}
	this->_nEquiped = 0;
	return ;
}
void						Character::describeBag(void) const
{
	for (int i = 0; i < this->_nEquiped; i++)
		std::cout << "#" << i << " " << this->_bag[i]->getName() << " " <<
			this->_bag[i]->getXP() << "xp" << std::endl;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
