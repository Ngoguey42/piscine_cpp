

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>

class Zombie
{
public:
	Zombie(std::string name, std::string type);
	~Zombie(void);
	void					announce(void);
	static std::string		types[3];
	static std::string		default_names[10];
private:
	std::string				_name;
	std::string				_type;
};

#endif
