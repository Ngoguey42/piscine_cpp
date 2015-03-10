
#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string const name, std::string const title);
	Sorcerer(Sorcerer const &rhs);
	~Sorcerer();
	Sorcerer				&operator=(Sorcerer const &rhs);
	
	std::string	const		&getName(void) const;
	std::string const		&getTitle(void) const;
	void					polymorph(Victim const &v) const;
	
private:
	std::string				_name;
	std::string				_title;
	Sorcerer();
};

std::ostream			&operator<<(std::ostream & o, Sorcerer const & rhs);

#endif // ****************************************************** SORCERER_HPP //
