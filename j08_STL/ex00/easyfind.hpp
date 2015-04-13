// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   easyfind.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 14:06:06 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/13 15:52:44 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <map>
//# include <stdexcept>

template<typename T>
void					easyfind(T const &c, int n)
{	
	if (std::find(c.begin(), c.end(), n) != c.end())
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	return ;
}

template<typename T>
void					easyfind(std::map<T, int> const &c, int n)
{
	for (typename std::map<T, int>::const_iterator it = c.begin();
		 it != c.end();
		 it++)
	{
		if (it->second == n)
		{
			std::cout << "OK" << std::endl;
			return ;
		}
	}
	std::cout << "KO" << std::endl;
	return ;
}

#endif // ****************************************************** EASYFIND_HPP //
