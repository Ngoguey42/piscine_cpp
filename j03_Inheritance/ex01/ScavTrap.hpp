
#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>

class ScavTrap
{
public:
	ScavTrap();
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string const name);
	~ScavTrap();
	ScavTrap				&operator=(ScavTrap const &rhs);
	
	void					rangedAttack(std::string const &target);
	void					meleeAttack(std::string const &target);
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);
	
	std::string const		name;
	std::string				getName(void)  const;
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
	void					clg_comeback(std::string const &target);
	void					clg_chicken(std::string const &target);
	void					clg_pansy(std::string const &target);
	void					clg_com(std::string const &target);
	void					challengeNewcomer(std::string const &target);
	
private:
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
