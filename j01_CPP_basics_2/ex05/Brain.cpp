
#include <sstream>
#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructed" << std::endl;
	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
	return ;
}

std::string				Brain::identify(void) const
{
	std::ostringstream oss;

	oss << (void*)this;
	std::string s();
	return (oss.str());
}
