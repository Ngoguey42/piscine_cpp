// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 08:14:03 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/15 10:21:22 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Array.template.hpp"

int							main(void)
{
	Array<int>		*a;
	Array<int>		*b;
	Array<std::string>		*d;
	Array<std::string>		*e;

	std::cout << std::endl;
	try
	{
		std::cout << "========>a = new Array<int>(4)" << std::endl;
		a = new Array<int>(4);
		std::cout << "Reading" << std::endl;
		for (int i = 0; i < 4; i++)
			std::cout << "(*a)[" << i << "]: "<< (*a)[i] << std::endl;
		std::cout << "Setting" << std::endl;
		for (int i = 0; i < 4; i++)
			(*a)[i] = (i + 1) * 42;
		std::cout << "Reading" << std::endl;
		for (int i = 0; i < 6; i++)
			std::cout << "(*a)[" << i << "]: "<< (*a)[i] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "========>b = new Array<int>" << std::endl;
		b = new Array<int>;
		std::cout << "Reading" << std::endl;
		std::cout << "(*b)[" << 0 << "]: "<< (*b)[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "========>*b = *a" << std::endl;
		*b = *a;
		std::cout << "Reading" << std::endl;
		for (int i = 0; i < 6; i++)
			std::cout << "(*b)[" << i << "]: "<< (*b)[i] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	
	
	try
	{
		std::cout << "d = new Array<std::string>(3)" << std::endl;
		d = new Array<std::string>(3);
		std::cout << "Reading" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "(*d)[" << i << "]: "<< (*d)[i] << std::endl;
		std::cout << "Setting" << std::endl;
		for (int i = 0; i < 3; i++)
			(*d)[i] = "salut";
		std::cout << "Reading" << std::endl;
		for (int i = 0; i < 6; i++)
			std::cout << "(*d)[" << i << "]: "<< (*d)[i] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "e = new Array<std::string>(*d)" << std::endl;
		e = new Array<std::string>(*d);
		std::cout << "Reading" << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << "(*d)[" << i << "]: "<< (*e)[i] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
