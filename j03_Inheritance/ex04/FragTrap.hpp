// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 08:57:11 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 16:01:29 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	// * NESTED OBJECTS ************* //
	typedef void			(FragTrap::*vh)(std::string const &target) const;

	// * STATICS ******************** //
	static FragTrap::vh		vh_tab[5];

	// * CTORS / DTORS ************** //
	FragTrap();
	FragTrap(bool);
	FragTrap(FragTrap const &src);
	FragTrap(std::string const &name);
	virtual ~FragTrap();
	FragTrap				&operator=(FragTrap const &rhs);
	
	// * MEMBER FUNCTIONS / METHODS * //
	virtual void            rangedAttack(std::string const &target) const;
	
	void					vaulthunter_dot_exe(std::string const &target);
	void					vh_funzerker(std::string const &target) const;
	void					vh_laserInferno(std::string const &target) const;
	void					vh_miniontrap(std::string const &target) const;
	void					vh_oneShotWonder(std::string const &target) const;
	void					vh_torgueFiesta(std::string const &target) const;
	
private:
	void                    loadDefaultStats(void);
};

#endif // **************************************************** FRAG_TRAP_HPP //
