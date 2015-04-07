// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 13:50:57 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 13:51:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_CLASS_HPP
# define HUMAN_CLASS_HPP

# include <iostream>
# include "Brain.hpp"

class Human
{
public:
	Human();
	~Human();
	std::string				identify(void) const;
	Brain const				&getBrain(void);
private:
	Brain const				_brain;
};

#endif
