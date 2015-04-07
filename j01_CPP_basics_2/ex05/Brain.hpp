// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:51:16 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 14:10:34 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>

class Brain
{
public:
	Brain();
	~Brain();
	std::string				identify(void) const;
private:
	unsigned short			_memory[32];
};

#endif
