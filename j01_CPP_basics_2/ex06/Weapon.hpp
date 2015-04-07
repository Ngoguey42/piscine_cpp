// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 14:18:36 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 14:21:09 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <iostream>
# include "Weapon.hpp"

class Weapon
{
public:
	Weapon(std::string const &type);
	~Weapon();
	void				setType(std::string const &type);
	std::string const	&getType(void) const;
private:
	std::string			_type;
};

#endif
