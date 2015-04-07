// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 12:54:58 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:43:42 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>

class Zombie
{
public:
	Zombie();
	~Zombie(void);
	void						announce(void) const;
	static std::string const	types[3];
	static std::string const	default_names[10];
private:
	std::string					_name;
	std::string					_type;
};

#endif
