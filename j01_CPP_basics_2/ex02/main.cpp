

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>

int			main(void)
{
	ZombieEvent		event;
	Zombie			*ptr;

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
