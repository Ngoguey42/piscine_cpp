// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/09 13:35:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 16:08:43 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int			main(void)
{
	std::cout << "Tests part 1" << std::endl;
	{
		SuperTrap	p0;
		p0.takeDamage(10);
		std::cout << std::endl;
		
		SuperTrap	p1("LOLNAME");
		p1.takeDamage(20);
		std::cout << std::endl;
		
		SuperTrap	p2(p0);
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
		SuperTrap	p1("Roger");
		SuperTrap	p2("Denis");
		std::cout << std::endl;
		
		p1.rangedAttack(p2.getName());
		p2.takeDamage(p1.getRangedDamage());
		std::cout << std::endl;

		p2.meleeAttack(p1.getName());
		p1.takeDamage(p2.getMeleeDamage());
		std::cout << std::endl;
		
		p1.vaulthunter_dot_exe(p2.getName());
		p1.vaulthunter_dot_exe(p2.getName());
		p1.vaulthunter_dot_exe(p2.getName());
		p1.vaulthunter_dot_exe(p2.getName());
		p1.vaulthunter_dot_exe(p2.getName());
		std::cout << std::endl;
	}
	return (0);
}
