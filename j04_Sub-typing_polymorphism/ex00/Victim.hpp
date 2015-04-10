// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 13:55:11 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:02:13 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
public:
	Victim(std::string const name);
	Victim(Victim const &rhs);
	~Victim();
	
	std::string const		&getName(void) const;
	virtual void			getPolymorphed(void) const;
	
protected:
	std::string				_name;
private:
	Victim					&operator=(Victim const &rhs);
	Victim();
};

std::ostream			&operator<<(std::ostream & o, Victim const & rhs);

#endif // ******************************************************** VICTIM_HPP //
