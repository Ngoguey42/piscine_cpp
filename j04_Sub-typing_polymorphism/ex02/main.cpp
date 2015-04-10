// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 15:13:31 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 15:47:15 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	
	std::cout << "====================part2=============" << std::endl;

	std::cout << "========= new squad of 2 =======" << std::endl;
	Squad	sq2;
	sq2.push(new TacticalMarine);
	sq2.push(new AssaultTerminator);
	std::cout << "========= new squad per copy + 1push =======" << std::endl;
	
	Squad	sq3(sq2);	
	sq3.push(new TacticalMarine);

	std::cout << "========= deleting =======" << std::endl;
	return 0;	
}
