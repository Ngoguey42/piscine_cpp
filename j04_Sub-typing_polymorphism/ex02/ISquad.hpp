// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISquad.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:32:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 14:37:03 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
public:
	virtual ~ISquad() {}
	virtual int					getCount() const = 0;
	virtual ISpaceMarine*		getUnit(int id) = 0;
	virtual int					push(ISpaceMarine* ptr) = 0;

};

#endif // ******************************************************** ISQUAD_HPP //
