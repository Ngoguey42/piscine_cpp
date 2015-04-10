// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:06:58 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:07:02 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef A_WEAPON_HPP
# define A_WEAPON_HPP

# include <iostream>

class AWeapon
{
public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &rhs);
	virtual ~AWeapon();
	AWeapon						&operator=(AWeapon const &rhs);
	
	int							getAPCost(void) const;
	int							getDamage(void) const;
	std::string const			&getName(void) const;
	std::string const			&getMsg(void) const;
	
	virtual void				attack(void) const = 0;
	
protected:
	AWeapon();
	std::string					_name;
	int							_damage;
	int							_aPCost;
	std::string					_msg;
};

// std::ostream			&operator<<(std::ostream & o, AWeapon const & rhs);

#endif // ****************************************************** A_WEAPON_HPP //
