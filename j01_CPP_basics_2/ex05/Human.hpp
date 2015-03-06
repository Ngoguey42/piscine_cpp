

#ifndef HUMAN_CLASS_HPP
# define HUMAN_CLASS_HPP

# include <iostream>
# include "Brain.hpp"

class Human
{
public:
	Human();
	~Human();
	std::string				identify(void) const;
	Brain const				&getBrain(void);
private:
	Brain const				_brain;
};

#endif
