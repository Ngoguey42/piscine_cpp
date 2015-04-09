// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 13:35:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 13:35:04 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int			main(void)
{
	std::cout << "Tests part 1" << std::endl;
	{
		NinjaTrap	p0;
		p0.takeDamage(10);
		std::cout << std::endl;
		
		NinjaTrap	p1("lol");
		p1.takeDamage(20);
		std::cout << std::endl;
		
		NinjaTrap	p2(p0);
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

		std::cout << std::endl;
		std::cout << "Pony and skull are now best friends." << std::endl;
		std::cout << std::endl;
		
		NinjaTrap	player1("Rogue");
		
		player1.ninjaShoebox(player3);
		player1.ninjaShoebox(player3);
		
		std::cout << std::endl;
		std::cout << "Skull doesn't move anymore..." << std::endl;
		std::cout << std::endl;
		
		player1.ninjaShoebox(player2);
		
		std::cout << std::endl;
		std::cout << "Pony is now very mad..." << std::endl;
		std::cout << std::endl;
		
		player2.meleeAttack(player1.getName());
		player1.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player1.getName());
		player1.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player1.getName());
		player1.takeDamage(player2.getMeleeDamage());
		
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		
		std::cout << std::endl;
		std::cout << "Rogue doesn't move anymore..." << std::endl;
		std::cout << std::endl;
		
		player2.beRepaired(100);
	}
	return (0);
}
