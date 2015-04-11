// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMateriaSource.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 12:38:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 13:06:27 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

//# include <string>
# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
public:
	// IMateriaSource();
	// IMateriaSource(IMateriaSource const &src);
	// IMateriaSource				&operator=(IMateriaSource const &rhs);
	virtual ~IMateriaSource(){}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
	
protected:
private:
};
//std::ostream					&operator<<(std::ostream &o, IMateriaSource const &rhs);

#endif // ************************************************ IMATERIASOURCE_HPP //
