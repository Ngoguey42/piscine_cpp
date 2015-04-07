// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 12:41:02 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 12:47:30 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"
#include <iostream>

Pony::Pony(int height, std::string const &name)
{
	std::cout << "Constructor called" << std::endl;
	this->_height = height;
	this->_name = name;
	return;
}

Pony::~Pony(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int					Pony::getHeight(void) const{return (this->_height);}
std::string const	&Pony::getName(void) const{return (this->_name);}
