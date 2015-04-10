// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:20:02 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:21:09 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
	Character(std::string const &name);
	virtual ~Character();
	
	std::string const			&getName(void) const;
	int							getAP(void) const;
	int							getAPMax(void) const;
	const AWeapon				*getWeapon(void) const;
	
	void						recoverAP(void);
	void						equip(AWeapon *wptr);
	void						attack(Enemy *eptr);
	
	
protected:
	Character();
	Character						&operator=(Character const &rhs);
	Character(Character const &rhs);
	
	std::string					_name;
	int							_aP;
	int							_aPMax;
	AWeapon						*_weaponPtr;
	static int const			_defaultAPMax;
	static int const			_defaultAPRecover;
};

std::ostream			&operator<<(std::ostream & o, Character const &rhs);

#endif // ***************************************************** CHARACTER_HPP //
