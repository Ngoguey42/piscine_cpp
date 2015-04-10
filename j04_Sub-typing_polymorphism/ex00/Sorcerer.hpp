// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 13:58:07 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:02:19 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string const name, std::string const title);
	Sorcerer(Sorcerer const &rhs);
	~Sorcerer();
	
	std::string	const		&getName(void) const;
	std::string const		&getTitle(void) const;
	void					polymorph(Victim const &v) const;
	
private:
	std::string				_name;
	std::string				_title;
	Sorcerer				&operator=(Sorcerer const &rhs);
	Sorcerer();
};

std::ostream			&operator<<(std::ostream & o, Sorcerer const & rhs);

#endif // ****************************************************** SORCERER_HPP //
