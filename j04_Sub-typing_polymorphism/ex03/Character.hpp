// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 13:10:36 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 13:29:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character(std::string const &name);
	Character(Character const &src);
	Character					&operator=(Character const &rhs);
	virtual ~Character();

	std::string const			&getName() const;
	void						equip(AMateria* m);
	void						unequip(int idx);
	void						use(int idx, ICharacter& target);

	
protected:
private:
	Character();
	std::string					_name;
	AMateria					*_bag[4];
	int							_nEquiped;
	
};
//std::ostream					&operator<<(std::ostream &o, Character const &rhs);

#endif // ***************************************************** CHARACTER_HPP //
