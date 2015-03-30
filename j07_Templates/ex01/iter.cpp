// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   iter.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 08:14:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 08:14:14 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

template <typename T>
void						iter(T array[], size_t s, void (*f)(T &))
{
	for (size_t i = 0;i < s;i++)
		f(array[i]);
	return ;
}

template <typename T>
static void					print(T &v)
{
	static int	i = 0;

	std::cout << "Val(" << i++ << "): " << v << std::endl;
	return ;
}

int							main(void)
{
	int				arrayi[5] = {42, 21, 10, 5, 2};
	std::string		arrays[5] = {"ft", "to", "ten", "five", "two"};

	std::cout << "ints:" << std::endl;
	iter(arrayi, sizeof(arrayi) / sizeof(int), &print);
	std::cout << "strings:" << std::endl;	
	iter(arrays, sizeof(arrays) / sizeof(std::string), &print);
	return (0);
}
