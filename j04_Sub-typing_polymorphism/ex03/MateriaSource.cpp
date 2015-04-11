// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 15:00:40 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/11 15:13:09 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "MateriaSource.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
MateriaSource::MateriaSource() :
	_knownMaterias(NULL),
	_knownNum(0)
{
	std::cout << "[MateriaSource]() Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						MateriaSource::learnMateria(AMateria *m)
{
	AMateria	**m_ptr;

	for (size_t i = 0; i < this->_knownNum; i++)
		if (this->_knownMaterias[i]->getName() == m->getName())
		{
			std::cout << "[MateriaSource]" << m->getName() <<
				" already known" << std::endl;
			
			return ;
		}
	m_ptr = new AMateria*[this->_knownNum + 1];
	for (size_t i = 0; i < this->_knownNum; i++)
		m_ptr[i] = this->_knownMaterias[i];
	m_ptr[this->_knownNum] = m;
	this->_knownNum++;
	if (this->_knownMaterias != NULL)
		delete this->_knownMaterias;
	this->_knownMaterias = m_ptr;
	return ;
}
AMateria					*MateriaSource::createMateria(
	std::string const &type)
{
	for (size_t i = 0; i < this->_knownNum; i++)
		if (this->_knownMaterias[i]->getName() == type)
			return (this->_knownMaterias[i]->clone());
	std::cout << "[MateriaSource]" << type <<
		" unknown" << std::endl;
	return (NULL);
}


// * NESTED_CLASSES ********************************************************* //
