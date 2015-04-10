// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RadScorpion.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:16:16 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:16:16 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

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
	static std::string const	_typeName;
	static int const			_baseHp;
	static std::string const	_birthMsg;
	static std::string const	_deathMsg;
};

// std::ostream			&operator<<(std::ostream & o, RadScorpion const & rhs);

#endif // ************************************************** RAD_SCORPION_HPP //
