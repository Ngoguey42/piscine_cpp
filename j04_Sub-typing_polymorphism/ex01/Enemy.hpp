// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:13:24 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:13:26 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
public:
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &rhs);
	virtual ~Enemy();
	Enemy					&operator=(Enemy const &rhs);
	
	int						getHp(void) const;
	std::string const		&getType(void) const;
	
	virtual void			takeDamage(int amount);
	
protected:
	Enemy();
	int						_hp;
	std::string				_type;
};

// std::ostream			&operator<<(std::ostream & o, Enemy const & rhs);

#endif // ********************************************************* ENEMY_HPP //
