// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   easyfind.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 14:06:06 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/13 14:48:09 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
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

#endif // ****************************************************** EASYFIND_HPP //
