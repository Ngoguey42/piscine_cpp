
#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
public:
	Victim(std::string const name);
	Victim(Victim const &rhs);
	~Victim();
	Victim					&operator=(Victim const &rhs);
	
	std::string const		&getName(void) const;
	virtual void			getPolymorphed(void) const;
	
protected:
	std::string				_name;
	Victim();
};

std::ostream			&operator<<(std::ostream & o, Victim const & rhs);

#endif // ******************************************************** VICTIM_HPP //
