
#include "ZombieEvent.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent(void)
{
	this->_curType = "None";
	return ;
}

ZombieEvent::~ZombieEvent(void){return ;}

void		ZombieEvent::setZombieType(std::string type)
{
	this->_curType = type;
	return ;
}

Zombie		*ZombieEvent::newZombie(std::string name)
{
	for (int i = 0; i < sizeof(Zombie::types) / sizeof(*Zombie::types); i++)
	{
		if (this->_curType.compare(Zombie::types[i]) == 0)
		{
			return (new Zombie(name, this->_curType));
		}
	}
	std::cout << this->_curType << ": wrong zombie type..." << std::endl;
	return (NULL);
}

static void	chump(std::string type)
{
	Zombie		z(
					Zombie::default_names[(std::rand() + std::time(0)) %
						(sizeof(Zombie::default_names) /
							sizeof(*Zombie::default_names))], 
					type
					);
	z.announce();
	return ;
}

void		ZombieEvent::randomChump(void)
{
	for (int i = 0; i < sizeof(Zombie::types) / sizeof(*Zombie::types); i++)
	{
		if (this->_curType.compare(Zombie::types[i]) == 0)
		{
			chump(this->_curType);
			return ;
		}
	}
	std::cout << this->_curType << ": wrong zombie type..." << std::endl;
	return ;
}
