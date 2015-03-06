
#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, std::string type)
{
	this->_name = name;
	this->_type = type;
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
