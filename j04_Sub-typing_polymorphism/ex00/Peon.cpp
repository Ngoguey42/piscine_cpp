// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 13:02:33 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 12:29:16 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "Peon.hpp"

// ************************************************************ CONSTRUCTORS //
Peon::Peon(Peon const & src) :
	Victim(src.getName())
{
	std::cout << "[Peon](src) constructor called!" << std::endl;
	return ;
}

Peon::Peon(std::string const name) :
	Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return ;
}
// ************************************************************* DESTRUCTORS //
Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
	return ;
}
// *************************************************************** OPERATORS //
Peon			&Peon::operator=(Peon const &rhs)
{
	std::cout << "[Peon]= called!" << std::endl;
	this->_name = rhs.getName();
	return (*this);
}
std::ostream		&operator<<(std::ostream & o, Peon const & rhs)
{
	o << "I'm " << rhs.getName() << " and i like otters !" << std::endl;
	return (o);

}
void				Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a pink pony !" <<
		std::endl;
	return ;
}
