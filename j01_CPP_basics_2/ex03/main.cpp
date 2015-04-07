// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:45:02 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:46:54 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>

int			main(void)
{
	srand(time(NULL));
	
	std::cout << "New horde of 3:" << std::endl;
	ZombieHorde	*horde = new ZombieHorde(3);
	horde->announce();
	delete(horde);
	std::cout << "New horde of 5:" << std::endl;
	horde = new ZombieHorde(5);
	horde->announce();
	delete(horde);
	return (0);
}
