
#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string const name);
	~ScavTrap();
	ClapTrap				&operator=(ClapTrap const &rhs);

	void					(ScavTrap::*challenges[4])
								(std::string const &target);
	void					clg_comeback(std::string const &target);
	void					clg_chicken(std::string const &target);
	void					clg_pansy(std::string const &target);
	void					clg_com(std::string const &target);
	void					challengeNewcomer(std::string const &target);
	
private:
	void					loadDefaultStats(void);
};

typedef void				(ScavTrap::*clg_attack)(std::string const &target);

#endif // **************************************************** SCAV_TRAP_HPP //
