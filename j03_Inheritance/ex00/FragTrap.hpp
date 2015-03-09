
#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>


class FragTrap
{
public:
	FragTrap();
	FragTrap(FragTrap const &src);
	FragTrap(std::string const name);
	~FragTrap();
	FragTrap				&operator=(FragTrap const &rhs);
	
	void					rangedAttack(std::string const &target);
	void					meleeAttack(std::string const &target);
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);
	
	void					(FragTrap::*vaulthunter_attacks[5])(std::string const &target);
	// void					(FragTrap::*vaulthunter_attack)(std::string const &target);
	void					vh_funzerker(std::string const &target);
	void					vh_laserInferno(std::string const &target);
	void					vh_miniontrap(std::string const &target);
	void					vh_oneShotWonder(std::string const &target);
	void					vh_torgueFiesta(std::string const &target);
	void					vaulthunter_dot_exe(std::string const &target);
	
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

typedef void				(FragTrap::*vh_attack)(std::string const &target);

#endif
