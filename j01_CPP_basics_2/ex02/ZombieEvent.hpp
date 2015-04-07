// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 12:53:55 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:25:41 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEEVENT_CLASS_HPP
# define ZOMBIEEVENT_CLASS_HPP

# include "Zombie.hpp"
# include <iostream>

class ZombieEvent
{
public:
	ZombieEvent(void);
	~ZombieEvent(void);
	void					setZombieType(std::string const &type);
	Zombie					*newZombie(std::string const &name);
	void					randomChump(void) const;
private:
	std::string				_curType;
};

#endif
