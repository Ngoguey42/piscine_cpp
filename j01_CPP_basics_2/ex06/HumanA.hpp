// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 14:19:35 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 14:26:38 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string const &name, Weapon &weapon);
	~HumanA();
	void				attack(void) const;
private:
	std::string const	_name;
	Weapon 				&_weapon;
};

#endif
