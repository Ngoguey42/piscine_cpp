
#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

# include <iostream>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	SuperMutant(SuperMutant const &rhs);
	virtual ~SuperMutant();
	SuperMutant 				&operator=(SuperMutant const &rhs);
	
	virtual void				takeDamage(int amount);
	
private:
	static std::string const	&_typeName;
	static int const			_baseHp;
	static std::string const	&_birthMsg;
	static std::string const	&_deathMsg;
};

// std::ostream			&operator<<(std::ostream & o, SuperMutant const & rhs);

#endif // ************************************************** SUPER_MUTANT_HPP //
