

#ifndef ZOMBIEEVENT_CLASS_HPP
# define ZOMBIEEVENT_CLASS_HPP

# include "Zombie.hpp"
# include <iostream>

class ZombieEvent
{
public:
	ZombieEvent(void);
	~ZombieEvent(void);
	void					setZombieType(std::string type);
	Zombie					*newZombie(std::string name);
	void					randomChump(void);
private:
	std::string				_curType;
};

#endif
