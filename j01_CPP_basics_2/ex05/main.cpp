// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:50:43 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:50:44 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"
# include <iostream>

int main(void)
{
	Human	bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}
