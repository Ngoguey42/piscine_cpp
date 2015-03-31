// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 18:14:48 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 18:59:20 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <cstdlib>

struct Data { std::string s1; int n; std::string s2; };

static char					getChar(int randval)
{
	if (randval < 10)
		return ('0' + std::rand() % 10);
	else if (randval < 24 + 10)
		return ('a' + std::rand() % 24);
	return ('A' + std::rand() % 24);
}

void						*serialize(void)
{
	char	*part1 = new char[sizeof(char) * 8 * 2 + sizeof(int)];
	char	*part3 = part1 + sizeof(char) * 8 + sizeof(int);
	int		*part2 = reinterpret_cast<int*>(part1 + sizeof(char) * 8);

	for (size_t i = 0; i < sizeof(char) * 8; i++)
	{
		part1[i] = getChar(std::rand() % (24 * 2 + 10));
		part3[i] = getChar(std::rand() % (24 * 2 + 10));
	}
	*part2 = std::rand();
	return (part1);
}

Data						*unserialize(void *raw)
{
	char	*part1 = reinterpret_cast<char*>(raw);
	char	*part3 = part1 + sizeof(char) * 8 + sizeof(int);
	int		*part2 = reinterpret_cast<int*>(part1 + sizeof(char) * 8);
	Data	*dat = new Data;

	dat->s1.resize(8);
	dat->s2.resize(8);
	for (size_t i = 0; i < sizeof(char) * 8; i++)
	{
		dat->s1[i] = part1[i];
		dat->s2[i] = part3[i];
	}
	dat->n = *part2;
	delete reinterpret_cast<char*>(raw);
	return (dat);
}

int							main(void)
{
	void	*dat;
	Data	*data;
	
	srand(time(NULL));
	dat = serialize();
	std::cout << (char*)dat << std::endl;
	data = unserialize(dat);
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
	return (0);
}
