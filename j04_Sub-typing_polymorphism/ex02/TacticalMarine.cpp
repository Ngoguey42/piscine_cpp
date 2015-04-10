// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:52:48 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 15:27:59 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "TacticalMarine.hpp"

// * STATICS **************************************************************** //
std::string const			TacticalMarine::_birthMgs =
	"Tactical Marine ready for battle";
std::string const			TacticalMarine::_battleCryMsg =
	"For the holy PLOT !";
std::string const			TacticalMarine::_rangedAttackMsg =
	"* attacks with bolter *";
std::string const			TacticalMarine::_meleeAttackMsg =
	"* attacks with chainsword *";
std::string const			TacticalMarine::_deathMgs =
	"Aaargh ...";

// * CONSTRUCTORS *********************************************************** //
TacticalMarine::TacticalMarine() :
	ISpaceMarine(),
	_next(NULL)
{
	std::cout << TacticalMarine::_birthMgs << std::endl;
	return ;
}
TacticalMarine::TacticalMarine(TacticalMarine const &src) :
	ISpaceMarine(),
	_next(NULL)
{
	std::cout << TacticalMarine::_birthMgs << std::endl;
	(void)src;
	return ;
}

// * DESTRUCTORS ************************************************************ //
TacticalMarine::~TacticalMarine()
{
	std::cout << TacticalMarine::_deathMgs << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
TacticalMarine				&TacticalMarine::operator=(
	TacticalMarine const &rhs)
{
	(void)rhs;
	return (*this);
}

// * GETTERS **************************************************************** //
ISpaceMarine				*TacticalMarine::getNext(void)
{return this->_next;}

// * SETTERS **************************************************************** //
void						TacticalMarine::setNext(ISpaceMarine *c)
{this->_next=c;}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
ISpaceMarine				*TacticalMarine::clone() const
{
	return (new TacticalMarine(*this));
}
void						TacticalMarine::battleCry() const
{
	std::cout << TacticalMarine::_battleCryMsg << std::endl;	
	return ;
}
void						TacticalMarine::rangedAttack() const
{
	std::cout << TacticalMarine::_rangedAttackMsg << std::endl;
	return ;
}
void						TacticalMarine::meleeAttack() const
{
	std::cout << TacticalMarine::_meleeAttackMsg << std::endl;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
