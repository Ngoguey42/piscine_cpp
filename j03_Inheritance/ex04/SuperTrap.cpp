// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 14:43:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 15:49:25 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "SuperTrap.hpp"

// ************************************************************* CONSTRUCTORS //
SuperTrap::SuperTrap() :
	NinjaTrap(true), FragTrap(true)
{
	std::cout << "Super Constructor called, How can I be of service?" <<
		std::endl;
	return ;
}
SuperTrap::SuperTrap(std::string const &name) :
	ClapTrap(name), NinjaTrap(name, true), FragTrap(true)
{
	std::cout << "Super Constructor(name) called, What do you need?" <<
		std::endl;
	return ;
}
SuperTrap::SuperTrap(SuperTrap const & src) :
	ClapTrap(src), NinjaTrap(src), FragTrap(src)
{
	std::cout << "Super Constructor(copy) called, Yes captain?" <<
		std::endl;
	this->_class = "SUP3R";
	return ;
}

// ************************************************************** DESTRUCTORS //
SuperTrap::~SuperTrap()
{
	std::cout << "Super Destructor called, Arrrrrghhh" << std::endl;
	return ;
}
// *************************************************************** OPERATORS //
SuperTrap            &SuperTrap::operator=(SuperTrap const &rhs)
{
	std::cout << "= overload called (super)" << std::endl;
	ClapTrap::operator = (rhs);
	return (*this);
}
