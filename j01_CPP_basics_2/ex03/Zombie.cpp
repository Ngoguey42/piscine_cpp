
#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Zombie::Zombie(void)
{
	this->_name = Zombie::default_names[rand() % 10];
	this->_type = Zombie::types[rand() % 3];
	return ;
}

Zombie::~Zombie(void){return ;}

void		Zombie::announce(void)
{
	std::cout << "<" << this->_name << " (" << this->_type <<
		")> Braiiiiinsss..." << std::endl;
	return ;
}

std::string	Zombie::types[3] = 
{
	"Boomer", "Hunter", "Witch"
};

std::string	Zombie::default_names[10] = 
{
	"Marco", "Polo", "Rocco", "Franco", "Macdo",
	"Waldo", "Rambo", "Pedro", "Rico", "Pecno"
};
