// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISpaceMarine.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:42:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 15:25:41 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine(){}
	virtual ISpaceMarine*		clone() const = 0;
	virtual void				battleCry() const = 0;
	virtual void				rangedAttack() const = 0;
	virtual void				meleeAttack() const = 0;
	
	virtual ISpaceMarine*		getNext() = 0;
	virtual void				setNext(ISpaceMarine*) = 0;
	
};

#endif // ************************************************** ISPACEMARINE_HPP //
