// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 13:01:32 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 15:16:57 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
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
	
	std::cout << "===[Flow test] ==========" << std::endl;	
	{
		std::cout << "{main} new source m" << std::endl;	
		MateriaSource	m;
		std::cout << "{main} learning patterns" << std::endl;	
		m.learnMateria(new Ice);
		m.learnMateria(new Cure);
		
		std::cout << "" << std::endl;
		std::cout << "{main} new character c1" << std::endl;	
		Character	c1("concon");
		std::cout << "" << std::endl;
		std::cout << "{main} c1.equip(m.createMateria(\"ice\"));" << std::endl;	
		c1.equip(m.createMateria("ice"));		
		
		std::cout << "" << std::endl;
		std::cout << "{main} new character c2(c1)" << std::endl;	
		Character	c2(c1);
		std::cout << "" << std::endl;
		std::cout << "{main} c2 bag:" << std::endl;
		c2.describeBag();
		std::cout << "{main} c2.equip(m.createMateria(\"cure\"));" << std::endl;
		c2.equip(m.createMateria("cure"));
		std::cout << "{main} c2.use(0, c1); x2" << std::endl;
		c2.use(0, c1);
		c2.use(0, c1);
		std::cout << "{main} c2 bag:" << std::endl;
		c2.describeBag();
		std::cout << "{main} c1 bag:" << std::endl;
		c1.describeBag();
		
		
		std::cout << "" << std::endl;		
		std::cout << "{main} c1=c2;" << std::endl;
		c1 = c2;
		std::cout << "{main} c1 bag:" << std::endl;
		c1.describeBag();
		
		std::cout << "" << std::endl;		
		


		(void)c2;
	}
	return (0);
}
