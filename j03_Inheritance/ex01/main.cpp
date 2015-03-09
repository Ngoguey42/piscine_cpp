
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int			main(void)
{
	ScavTrap	player2("Pony");
	FragTrap	player3("Skull");

	player3.rangedAttack(player2.getName());
	player2.takeDamage(player3.getRangedDamage());
	
	player3.meleeAttack(player2.getName());
	player2.takeDamage(player3.getMeleeDamage());
	
	std::cout << std::endl;
	std::cout << "Pony is now very mad..." << std::endl;
	std::cout << std::endl;
	
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
	player2.meleeAttack(player3.getName());
	player3.takeDamage(player2.getMeleeDamage());
	
	player2.challengeNewcomer(player3.getName());
	player2.challengeNewcomer(player3.getName());
	player2.challengeNewcomer(player3.getName());
	player2.challengeNewcomer(player3.getName());
	player2.challengeNewcomer(player3.getName());
	player2.challengeNewcomer(player3.getName());
	
	player2.meleeAttack(player3.getName());
	player3.takeDamage(player2.getMeleeDamage());
	
	std::cout << std::endl;
	std::cout << "Skull doesn't move anymore..." << std::endl;
	std::cout << std::endl;
	
	player2.beRepaired(100);
	return (0);
}
