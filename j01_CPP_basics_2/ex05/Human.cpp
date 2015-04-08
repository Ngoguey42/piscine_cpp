// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:51:07 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/08 08:53:31 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"
#include "Human.hpp"

Human::Human()
{
	std::cout << "Human constructed" << std::endl;
	return ;
}

Human::~Human()
{
	std::cout << "Human destructed" << std::endl;
	return ;
}

std::string				Human::identify(void) const
{
	return(this->_brain.identify());
}

Brain const				&Human::getBrain(void) const
{
	return (this->_brain);
}
