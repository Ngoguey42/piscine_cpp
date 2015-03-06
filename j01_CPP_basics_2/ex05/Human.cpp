
#include "Brain.hpp"
#include "Human.hpp"

Human::Human()
{
	std::cout << "Human constructed" << std::endl;
	return ;
}

Human::~Human()
{
	std::cout << "Human destructed" << std::endl;
	return ;
}

std::string				Human::identify(void) const
{
	return(this->_brain.identify());
}

Brain const				&Human::getBrain(void)
{
	return (this->_brain);
}
