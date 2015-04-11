// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cure.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 14:51:34 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 14:51:39 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CURE_HPP
# define CURE_HPP

//# include <string>
# include <iostream>
# include <stdexcept>
# include "AMateria.hpp"

class Cure : public AMateria
{
public:	
	Cure();
	Cure(Cure const &src);
	Cure							&operator=(Cure const &rhs);
	virtual ~Cure();

	AMateria					*clone() const;
	void						use(ICharacter& target);
	
protected:
private:
	static std::string const	_useMsg1;
	static std::string const	_useMsg2;
	static std::string const	_name;
	
};
//std::ostream					&operator<<(std::ostream &o, Cure const &rhs);

#endif // ********************************************************** CURE_HPP //
