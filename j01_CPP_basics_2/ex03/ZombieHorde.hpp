

#ifndef ZOMBIEHORDE_CLASS_HPP
# define ZOMBIEHORDE_CLASS_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int len);
	~ZombieHorde(void);
	void					announce(void);
private:
	Zombie					*_zombies;
	int						_len;
};

#endif
