// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/06 11:33:02 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/06 11:41:20 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

static char		format_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

static void		format_string(char *str)
{
	for (;*str != '\0';str++)
		*str = format_char(*str);
	return ;
}

int			main(int ac, char *av[])
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (av++; --ac; av++)
	{	
		format_string(*av);
		std::cout << *av;
	}
	std::cout << std::endl;
	return (0);
}
