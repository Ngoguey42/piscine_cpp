// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ICharacter.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:37:12 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 13:04:38 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

//# include <string>
# include <iostream>
class AMateria;
# include "AMateria.hpp"

class ICharacter
{
public:
	// ICharacter();
	// ICharacter(ICharacter const &src);
	// ICharacter					&operator=(ICharacter const &rhs);
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

protected:
private:
};
//std::ostream					&operator<<(std::ostream &o, ICharacter const &rhs);

#endif // **************************************************** ICHARACTER_HPP //
