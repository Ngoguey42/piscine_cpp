// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 15:29:38 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 15:31:33 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "AssaultTerminator.hpp"

// * STATICS **************************************************************** //
std::string const			AssaultTerminator::_birthMgs =
	"* teleports from space *";
std::string const			AssaultTerminator::_battleCryMsg =
	"This code is unclean. PURIFY IT !";
std::string const			AssaultTerminator::_rangedAttackMsg =
	"* does nothing *";
std::string const			AssaultTerminator::_meleeAttackMsg =
	"* attacks with chainfists *";
std::string const			AssaultTerminator::_deathMgs =
	"I’ll be back ...";

// * CONSTRUCTORS *********************************************************** //
AssaultTerminator::AssaultTerminator() :
	ISpaceMarine(),
	_next(NULL)
{
	std::cout << AssaultTerminator::_birthMgs << std::endl;
	return ;
}
AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) :
	ISpaceMarine(),
	_next(NULL)
{
	std::cout << AssaultTerminator::_birthMgs << std::endl;
	(void)src;
	return ;
}

// * DESTRUCTORS ************************************************************ //
AssaultTerminator::~AssaultTerminator()
{
	std::cout << AssaultTerminator::_deathMgs << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
AssaultTerminator			&AssaultTerminator::operator=(
	AssaultTerminator const &rhs)
{
	(void)rhs;
	return (*this);
}

// * GETTERS **************************************************************** //
ISpaceMarine				*AssaultTerminator::getNext(void)
{return this->_next;}

// * SETTERS **************************************************************** //
void						AssaultTerminator::setNext(ISpaceMarine *c)
{this->_next=c;}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
ISpaceMarine				*AssaultTerminator::clone() const
{
	return (new AssaultTerminator(*this));
}
void						AssaultTerminator::battleCry() const
{
	std::cout << AssaultTerminator::_battleCryMsg << std::endl;	
	return ;
}
void						AssaultTerminator::rangedAttack() const
{
	std::cout << AssaultTerminator::_rangedAttackMsg << std::endl;
	return ;
}
void						AssaultTerminator::meleeAttack() const
{
	std::cout << AssaultTerminator::_meleeAttackMsg << std::endl;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
