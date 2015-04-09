// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 14:43:06 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 16:07:27 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP

// class NinjaTrap;
// class FragTrap;

# include <iostream>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap();
	SuperTrap(SuperTrap const &src);
	SuperTrap(std::string const &name);
	virtual ~SuperTrap();
	SuperTrap				&operator=(SuperTrap const &rhs);

private:
	void					loadDefaultStats(void);
};

// typedef void				(SuperTrap::*clg_attack)(std::string const &target);

#endif // **************************************************** SUPER_TRAP_HPP //
