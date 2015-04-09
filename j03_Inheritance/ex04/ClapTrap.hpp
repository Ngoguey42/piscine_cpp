// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 12:38:11 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 15:14:07 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(ClapTrap const &src);
	ClapTrap(std::string const &name);
	virtual ~ClapTrap();
	ClapTrap				&operator=(ClapTrap const &rhs);

	virtual void			rangedAttack(std::string const &target) const;
	virtual void			meleeAttack(std::string const &target) const;
	virtual void			takeDamage(unsigned int amount);
	virtual void			beRepaired(unsigned int amount);
	
	std::string const		&getName(void)  const;
	unsigned int			getHp(void)  const;
	unsigned int			getHpMax(void)  const;
	unsigned int			getMana(void)  const;
	unsigned int			getManaMax(void)  const;
	unsigned int			getLevel(void)  const;
	unsigned int			getMeleeDamage(void)  const;
	unsigned int			getRangedDamage(void)  const;
	unsigned int			getArmorReduction(void)  const;
	
protected:
	std::string const		_name;
	unsigned int			_hp;
	unsigned int			_hpMax;
	unsigned int			_mana;
	unsigned int			_manaMax;
	unsigned int			_level;
	unsigned int			_meleeDamage;
	unsigned int			_rangedDamage;
	unsigned int			_armorReduction;
	std::string				_class;
};

#endif // **************************************************** CLAP_TRAP_HPP //
