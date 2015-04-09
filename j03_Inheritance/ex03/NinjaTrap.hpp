// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 13:28:31 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 13:34:54 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(NinjaTrap const &src);
	NinjaTrap(std::string const name);
	virtual ~NinjaTrap();
	NinjaTrap				&operator=(NinjaTrap const &rhs);

	void					ninjaShoebox(FragTrap &target);
	void					ninjaShoebox(ScavTrap &target);
	void					ninjaShoebox(NinjaTrap &target);
private:
	void					loadDefaultStats(void);
};

// typedef void				(NinjaTrap::*clg_attack)(std::string const &target);

#endif // **************************************************** NINJA_TRAP_HPP //
