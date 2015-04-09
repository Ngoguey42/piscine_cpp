// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 08:57:11 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 12:46:33 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>

class FragTrap
{
public:
	// * NESTED OBJECTS ************* //
	typedef void			(FragTrap::*vh)(std::string const &target) const;

	// * STATICS ******************** //
	static FragTrap::vh		vh_tab[5];

	// * CTORS / DTORS ************** //
	FragTrap();
	FragTrap(FragTrap const &src);
	FragTrap(std::string const &name);
	~FragTrap();
	FragTrap				&operator=(FragTrap const &rhs);
	
	// * ATTRIBUTES ***************** //

	// * GETTERS / SETTERS ********** //
	std::string const		&getName(void) const;
	unsigned int			getHp(void) const;
	unsigned int			getHpMax(void) const;
	unsigned int			getMana(void) const;
	unsigned int			getManaMax(void) const;
	unsigned int			getLevel(void) const;
	unsigned int			getMeleeDamage(void) const;
	unsigned int			getRangedDamage(void) const;
	unsigned int			getArmorReduction(void) const;

	// * MEMBER FUNCTIONS / METHODS * //
	void					rangedAttack(std::string const &target) const;
	void					meleeAttack(std::string const &target) const;
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);

	void					vaulthunter_dot_exe(std::string const &target);
	void					vh_funzerker(std::string const &target) const;
	void					vh_laserInferno(std::string const &target) const;
	void					vh_miniontrap(std::string const &target) const;
	void					vh_oneShotWonder(std::string const &target) const;
	void					vh_torgueFiesta(std::string const &target) const;

	
private:
	// * ATTRIBUTES ***************** //
	std::string const		_name;
	unsigned int			_hp;
	unsigned int			_hpMax;
	unsigned int			_mana;
	unsigned int			_manaMax;
	unsigned int			_level;
	unsigned int			_meleeDamage;
	unsigned int			_rangedDamage;
	unsigned int			_armorReduction;
};

#endif // **************************************************** FRAG_TRAP_HPP //
