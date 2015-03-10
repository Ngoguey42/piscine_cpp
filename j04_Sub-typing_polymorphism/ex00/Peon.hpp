
#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string const name);
	Peon(Peon const &rhs);
	~Peon();
	Peon					&operator=(Peon const &rhs);
	
	virtual void			getPolymorphed(void) const;
	
private:
	Peon();
};

std::ostream			&operator<<(std::ostream & o, Peon const & rhs);

#endif // ********************************************************** PEON_HPP //
