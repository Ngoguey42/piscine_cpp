// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 07:54:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/24 08:37:35 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <Converter.hpp>

int							main(int ac, char *av[])
{
	if (ac == 2)
	{
		Converter		cv(static_cast<std::string>(av[1]));

		cv.describeAsChar();
		cv.describeAsInt();
		cv.describeAsFloat();
		cv.describeAsDouble();
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
	return (0);
}
