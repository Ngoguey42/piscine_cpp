// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 12:52:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:02:38 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

int			main(void)
{
	ZombieEvent		event;
	Zombie			*ptr;

	srand(time(NULL));
	std::cout << "main: event.setZombieType(\"Boomer\")" << std::endl;
	event.setZombieType("Boomer");
	std::cout << std::endl;
	
	
	std::cout << "main: ptr = event.newZombie(\"John\")" << std::endl;
	ptr = event.newZombie("John");
	if (ptr != NULL)
	{
		std::cout << "main: ptr.announce()" << std::endl;
		ptr->announce();
		std::cout << "main: delete ptr" << std::endl;
		delete ptr;
	}
	std::cout << std::endl;
	
	
	std::cout << "main: ptr = event.newZombie(\"Marc\")" << std::endl;
	ptr = event.newZombie("Marc");
	if (ptr != NULL)
	{
		std::cout << "main: ptr.announce()" << std::endl;
		ptr->announce();
		std::cout << "main: delete ptr" << std::endl;
		delete ptr;
	}
	std::cout << std::endl;
	
	
	std::cout << "main: event.setZombieType(\"Witch\")" << std::endl;
	event.setZombieType("Witch");
	std::cout << std::endl;
	
	
	std::cout << "main: ptr = event.newZombie(\"Clara\")" << std::endl;
	ptr = event.newZombie("Clara");
	if (ptr != NULL)
	{
		std::cout << "main: ptr.announce()" << std::endl;
		ptr->announce();
		std::cout << "main: delete ptr" << std::endl;
		delete ptr;
	}
	std::cout << std::endl;
	
	
	std::cout << "main: event.setZombieType(\"Hunter\")" << std::endl;
	event.setZombieType("Hunter");
	std::cout << std::endl;
	
	
	std::cout << "main: event.randomChump()" << std::endl;
	event.randomChump();
	std::cout << "main: event.randomChump()" << std::endl;
	event.randomChump();
	std::cout << "main: event.randomChump()" << std::endl;
	event.randomChump();
	std::cout << "main: event.randomChump()" << std::endl;
	event.randomChump();
	std::cout << "main: event.randomChump()" << std::endl;
	event.randomChump();
	
	return (0);
}
