// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex04.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:49:37 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:49:47 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int			main(void)
{
	std::string		str("HI THIS IS BRAIN");
	std::string		*ptr = &str;
	std::string		&ref = str;
	
	std::cout << str << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	
	return (0);
}
