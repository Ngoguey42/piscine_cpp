// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 11:27:12 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 12:36:49 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// * NESTED OBJECTS ************* //
	typedef void(ScavTrap::*clg)(std::string const &target) const;

	// * STATICS ******************** //
	static ScavTrap::clg	clg_tab[4];
	
	// * CTORS / DTORS ************** //
	ScavTrap();
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string const &name);
	virtual ~ScavTrap();
	ScavTrap				&operator=(ScavTrap const &rhs);

	// * MEMBER FUNCTIONS / METHODS * //

	void					clg_comeback(std::string const &target) const;
	void					clg_chicken(std::string const &target) const;
	void					clg_pansy(std::string const &target) const;
	void					clg_com(std::string const &target) const;
	void					challengeNewcomer(std::string const &target);
	
private:
	void                    loadDefaultStats(void);
};

#endif // **************************************************** SCAV_TRAP_HPP //
