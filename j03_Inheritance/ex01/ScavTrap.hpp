// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 11:27:12 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 11:34:52 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>

class ScavTrap
{
public:
	// * NESTED OBJECTS ************* //
	typedef void(ScavTrap::*clg)(std::string const &target) const;

	// * STATICS ******************** //
	static ScavTrap::clg	clg_tab[4];
	
	// * CTORS / DTORS ************** //
	ScavTrap();
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string const name);
	~ScavTrap();
	ScavTrap				&operator=(ScavTrap const &rhs);

	// * GETTERS / SETTERS ********** //
	std::string const		&getName(void)  const;
	unsigned int			getHp(void)  const;
	unsigned int			getHpMax(void)  const;
	unsigned int			getMana(void)  const;
	unsigned int			getManaMax(void)  const;
	unsigned int			getLevel(void)  const;
	unsigned int			getMeleeDamage(void)  const;
	unsigned int			getRangedDamage(void)  const;
	unsigned int			getArmorReduction(void)  const;
	
	void					(ScavTrap::*challenges[4])
								(std::string const &target);

	// * MEMBER FUNCTIONS / METHODS * //
	void					rangedAttack(std::string const &target) const;
	void					meleeAttack(std::string const &target) const;
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);

	void					clg_comeback(std::string const &target) const;
	void					clg_chicken(std::string const &target) const;
	void					clg_pansy(std::string const &target) const;
	void					clg_com(std::string const &target) const;
	void					challengeNewcomer(std::string const &target);
	
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

typedef void				(ScavTrap::*clg_attack)(std::string const &target);

#endif // **************************************************** SCAV_TRAP_HPP //
