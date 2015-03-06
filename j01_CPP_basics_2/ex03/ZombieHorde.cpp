
#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(int len)
{
	this->_len = len;
	this->_zombies = new Zombie[len];
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_zombies;
	return ;
}

void		ZombieHorde::announce(void)
{
	for (int i = 0; i < this->_len; i++)
	{
		this->_zombies[i].announce();
	}
	return ;
}