// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex01.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 12:48:05 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 12:48:17 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

void	memoryLeak()
{
	std::string* panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;
	delete panthere;
}
