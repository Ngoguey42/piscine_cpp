// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 12:42:00 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 12:42:01 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int			main(void)
{
	std::cout << "Tests part 1" << std::endl;
	{
		FragTrap	p0;
		p0.takeDamage(10);
		std::cout << std::endl;
		
		FragTrap	p1("lol");
		p1.takeDamage(20);
		std::cout << std::endl;
		
		FragTrap	p2(p0);
		p2.takeDamage(30);
		std::cout << std::endl;
		
		std::cout << "p2 hp:" << p2.getHp() << std::endl;
		p2 = p1;
		std::cout << "p2 hp:" << p2.getHp() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Tests part 2" << std::endl;
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
	}
	return (0);
}
