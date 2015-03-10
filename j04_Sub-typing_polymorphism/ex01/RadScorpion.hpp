
#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP

# include <iostream>
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion();
	RadScorpion(RadScorpion const &rhs);
	virtual ~RadScorpion();
	RadScorpion 				&operator=(RadScorpion const &rhs);
	
private:
	static std::string const	&_typeName;
	static int const			_baseHp;
	static std::string const	&_birthMsg;
	static std::string const	&_deathMsg;
};

// std::ostream			&operator<<(std::ostream & o, RadScorpion const & rhs);

#endif // ************************************************** RAD_SCORPION_HPP //
