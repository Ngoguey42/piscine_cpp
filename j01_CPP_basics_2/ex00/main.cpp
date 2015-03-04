
#include "Pony.hpp"
#include <iostream>

void	ponyOnTheHeap(int height, std::string name)
{
	std::cout << "Entering on the heap!!" << std::endl;
	Pony	*p = new Pony(height, name);
	std::cout << "We've got a brand new pony!! " <<
		p->getHeight() << "cm tall called " <<
		p->getName() << std::endl;
	delete p;
	std::cout << "Leaving on the heap!!" << std::endl;
	return ;
}

void	ponyOnTheStack(int height, std::string name)
{
	std::cout << "Entering on the stack!!" << std::endl;
	Pony	p = Pony(height, name);
	std::cout << "We've got a brand new pony!! " <<
		p.getHeight() << "cm tall called " <<
		p.getName() << std::endl;
	std::cout << "Leaving on the stack!!" << std::endl;
	return ;
}

int		main(void)
{
	std::cout << "Calling on the heap..." << std::endl;
	ponyOnTheHeap(100, "Runner");
	std::cout << std::endl << std::endl;
	std::cout << "Calling on the stack..." << std::endl;
	ponyOnTheStack(110, "Screamer");
	return (0);
}
