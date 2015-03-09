
#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(FragTrap const &src);
	FragTrap(std::string const name);
	~FragTrap();
	ClapTrap				&operator=(ClapTrap const &rhs);
	
	void					(FragTrap::*vaulthunter_attacks[5])
								(std::string const &target);
	void					vh_funzerker(std::string const &target);
	void					vh_laserInferno(std::string const &target);
	void					vh_miniontrap(std::string const &target);
	void					vh_oneShotWonder(std::string const &target);
	void					vh_torgueFiesta(std::string const &target);
	void					vaulthunter_dot_exe(std::string const &target);
	
private:
};

typedef void				(FragTrap::*vh_attack)(std::string const &target);

#endif // **************************************************** FRAG_TRAP_HPP //
