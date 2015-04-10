// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:35:31 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 15:16:05 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
public:
	Squad();
	Squad(Squad const &src);
	Squad						&operator=(Squad const &rhs);
	virtual ~Squad();
	int							getCount() const;
	ISpaceMarine				*getUnit(int id);
	ISpaceMarine				*getUnit(int id) const;
	int							push(ISpaceMarine* ptr);

protected:
private:
	void						deleteUnits(void);
	
	int							_count;
	ISpaceMarine				*_aUnit;
};

#endif // ********************************************************* SQUAD_HPP //
