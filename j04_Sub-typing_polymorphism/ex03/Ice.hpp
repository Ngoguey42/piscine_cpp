// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ice.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:40:42 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 13:05:49 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ICE_HPP
# define ICE_HPP

//# include <string>
# include <iostream>
# include <stdexcept>
# include "AMateria.hpp"

class Ice : public AMateria
{
public:	
	Ice();
	Ice(Ice const &src);
	Ice							&operator=(Ice const &rhs);
	virtual ~Ice();

	AMateria					*clone() const;
	void						use(ICharacter& target);
	
protected:
private:
	static std::string const	_useMsg1;
	static std::string const	_useMsg2;
	static std::string const	_name;
	
};
//std::ostream					&operator<<(std::ostream &o, Ice const &rhs);

#endif // *********************************************************** ICE_HPP //
