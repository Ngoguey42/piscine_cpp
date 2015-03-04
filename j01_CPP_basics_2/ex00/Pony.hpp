
#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony
{
public:
	Pony(int height, std::string name);
	~Pony(void);
	int&			getHeight(void);
	std::string&	getName(void);
private:
	std::string		_name;
	int				_height;
};

#endif
