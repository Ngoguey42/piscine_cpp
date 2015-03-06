

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>

int			main(void)
{
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
