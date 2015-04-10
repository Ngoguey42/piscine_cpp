// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 13:02:29 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:02:23 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string const name);
	Peon(Peon const &rhs);
	~Peon();
	
	virtual void			getPolymorphed(void) const;
	
private:
	Peon					&operator=(Peon const &rhs);
	Peon();
};

std::ostream			&operator<<(std::ostream & o, Peon const & rhs);

#endif // ********************************************************** PEON_HPP //
