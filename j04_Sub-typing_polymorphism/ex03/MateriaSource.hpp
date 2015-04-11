// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 14:56:22 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 15:11:08 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

//# include <string>
# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	virtual ~MateriaSource();

	void					learnMateria(AMateria *m);
	AMateria				*createMateria(std::string const &type);
	
protected:
private:
	MateriaSource(MateriaSource const &src);
	MateriaSource				&operator=(MateriaSource const &rhs);

	AMateria				**_knownMaterias;
	size_t					_knownNum;
	
};
//std::ostream					&operator<<(std::ostream &o, MateriaSource const &rhs);

#endif // ************************************************* MATERIASOURCE_HPP //
