// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 13:01:32 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 13:29:15 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include <iostream>

int							main(void)
{
	
	std::cout << "===[Materias] Ctors Dtors Assignations===========" << std::endl;
	{
		Ice		m1;
		std::cout << "" << std::endl;
	
	
		Ice		m2(m1);

		std::cout << "" << std::endl;
		(void)m1;

		m2 = m1;
		std::cout << "" << std::endl;
	}
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	
	std::cout << "===[Character] Ctors Dtors Assignations==========" << std::endl;	
	{
		Character	c1("concon");
		std::cout << "" << std::endl;
		
		Character	c2(c1);
		std::cout << "" << std::endl;




		(void)c2;
	}
	return (0);
}
