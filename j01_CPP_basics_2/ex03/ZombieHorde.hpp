// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:45:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:45:39 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEHORDE_CLASS_HPP
# define ZOMBIEHORDE_CLASS_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int len);
	~ZombieHorde(void);
	void					announce(void);
private:
	Zombie					*_zombies;
	int						_len;
};

#endif
