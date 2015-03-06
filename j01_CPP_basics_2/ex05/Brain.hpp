

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>

class Brain
{
public:
	Brain();
	~Brain();
	std::string				identify(void) const;
private:
	unsigned short			_memory[32];
};

#endif
