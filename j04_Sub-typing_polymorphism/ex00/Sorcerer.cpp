// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 13:58:10 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:01:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "Sorcerer.hpp"
#include "Victim.hpp"

// ************************************************************************* //
// ************************************************************ CONSTRUCTORS //
Sorcerer::Sorcerer(Sorcerer const & src) :
_name(src.getName()), _title(src.getTitle())
{
	std::cout << "[Sorcerer](src) constructor called!" << std::endl;
	return ;
}

Sorcerer::Sorcerer(std::string const name, std::string const title) :
_name(name), _title(title)
{
	std::cout << name << ", "<< title << ", is born !" << std::endl;
	return ;
}
// CONSTRUCTORS ************************************************************ //
// ************************************************************************* //
// ************************************************************* DESTRUCTORS //
Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", "<< this->_title << ", is dead. "
		"Consequences will never be the same !" << std::endl;
	return ;
}
// DESTRUCTORS ************************************************************* //
// ************************************************************************* //
// *************************************************************** OPERATORS //
Sorcerer			&Sorcerer::operator=(Sorcerer const &rhs)
{
	std::cout << "[Sorcerer]= called!" << std::endl;
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	return (*this);
}
std::ostream		&operator<<(std::ostream & o, Sorcerer const & rhs)
{
	o << "I am " << rhs.getName() << ", "<< rhs.getTitle() <<
		", and I like ponies !" << std::endl;
	return (o);
}
// OPERATORS *************************************************************** //
// ************************************************************************* //
// ***************************************************************** GETTERS //
std::string	const	&Sorcerer::getName(void) const{return (this->_name);}
std::string	const	&Sorcerer::getTitle(void) const{return (this->_title);}
// GETTERS ***************************************************************** //
// ************************************************************************* //
// ***************************************************************** SETTERS //
// SETTERS ***************************************************************** //
// ************************************************************************* //
void				Sorcerer::polymorph(Victim const &v) const
{
	v.getPolymorphed();
	return ;
}
