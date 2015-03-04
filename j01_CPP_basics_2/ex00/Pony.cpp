
#include "Pony.hpp"
#include <iostream>

Pony::Pony(int height, std::string name)
{
	std::cout << "Constructor called" << std::endl;
	this->_height = height;
	this->_name = name;
	return;
}

Pony::~Pony(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int&			Pony::getHeight(void){ return (this->_height);}
std::string&	Pony::getName(void){ return (this->_name);}
