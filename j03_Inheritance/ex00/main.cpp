
#include <iostream>
#include "FragTrap.hpp"

int			main(void)
{
	FragTrap	player2("Pony");
	FragTrap	player3("Skull");

	player3.rangedAttack(player2.getName());
	player2.takeDamage(player3.getRangedDamage());
	
	player3.meleeAttack(player2.getName());
	player2.takeDamage(player3.getMeleeDamage());
	
	std::cout << "Pony is now very mad..." << std::endl;
	
	player2.meleeAttack(player3.getName());
	player3.takeDamage(player2.getMeleeDamage());
	player2.meleeAttack(player3.getName());
	player3.takeDamage(player2.getMeleeDamage());
	player2.meleeAttack(player3.getName());
	player3.takeDamage(player2.getMeleeDamage());
	player2.meleeAttack(player3.getName());
	player3.takeDamage(player2.getMeleeDamage());
	player2.meleeAttack(player3.getName());
	player3.takeDamage(player2.getMeleeDamage());
	
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	
	std::cout << "Skull doesn't move anymore..." << std::endl;
	
	player2.beRepaired(100);
	return (0);
}
