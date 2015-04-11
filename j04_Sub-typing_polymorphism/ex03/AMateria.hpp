// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMateria.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:39:01 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 13:24:03 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

//# include <string>
# include <iostream>
class ICharacter;
# include "ICharacter.hpp"

class AMateria
{
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	
	std::string const			&getType() const; //Returns the materia type
	std::string const			&getName(void) const;

	unsigned int				getXP() const; //Returns the Materia's XP
	virtual AMateria			*clone() const = 0;
	virtual void				use(ICharacter& target);
	
protected:
	AMateria(AMateria const &src);
	AMateria					&operator=(AMateria const &rhs);
	
private:
	AMateria();
	unsigned int				_XP;
	std::string const			_name;
	
};
//std::ostream					&operator<<(std::ostream &o, AMateria const &rhs);

#endif // ****************************************************** AMATERIA_HPP //
