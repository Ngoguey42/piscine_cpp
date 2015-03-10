
#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(NinjaTrap const &src);
	NinjaTrap(std::string const name);
	~NinjaTrap();
	ClapTrap				&operator=(ClapTrap const &rhs);

	void					ninjaShoebox(FragTrap &target);
	void					ninjaShoebox(ScavTrap &target);
	void					ninjaShoebox(NinjaTrap &target);
private:
	void					loadDefaultStats(void);
};

// typedef void				(NinjaTrap::*clg_attack)(std::string const &target);

#endif // **************************************************** NINJA_TRAP_HPP //
