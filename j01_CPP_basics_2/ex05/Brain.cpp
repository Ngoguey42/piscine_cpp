// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:51:25 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 14:10:18 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sstream>
#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 32 ; i++)
		this->_memory[i] = rand() % 64000;
	std::cout << "Brain constructed" << std::endl;
	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
	return ;
}

std::string				Brain::identify(void) const
{
	std::ostringstream oss;

	oss << (void*)this;
	return (oss.str());
}
