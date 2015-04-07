// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 12:40:31 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 12:47:25 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony
{
public:
	Pony(int height, std::string const &name);
	~Pony(void);
	int					getHeight(void) const;
	std::string const	&getName(void) const;

private:
	std::string		_name;
	int				_height;
};

#endif
