// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:07:07 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 15:32:30 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "OfficeBlock.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
OfficeBlock::OfficeBlock() :
	_intern(NULL),
	_signer(NULL),
	_executer(NULL)
{
	std::cout << "[OfficeBlock]() Ctor called" << std::endl;
	return ;
}
OfficeBlock::OfficeBlock(Intern const *intern, Bureaucrat const *signer, 
						 Bureaucrat const *executer) :
	_intern(intern),
	_signer(signer),
	_executer(executer)
{
	std::cout << "[OfficeBlock](Intern const*,Bureaucrat const*,"
		"Bureaucrat const*) Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
OfficeBlock::~OfficeBlock()
{
	std::cout << "[OfficeBlock]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
void						OfficeBlock::setIntern(Intern const *c)
{this->_intern=c;}
void						OfficeBlock::setSigner(Bureaucrat const *c)
{this->_signer=c;}
void						OfficeBlock::setExecuter(Bureaucrat const *c)
{this->_executer=c;}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
Form						*OfficeBlock::doBureaucracy(
	std::string const &name, std::string const &target)
	
{
	Form		*ret = NULL;

	if (this->_intern == NULL)
		throw MissingIntern();
	else if (this->_signer == NULL)
		throw MissingSigner();
	else if (this->_executer == NULL)
		throw MissingExecuter();
	ret = this->_intern->makeForm(name, target);
	this->_signer->signForm(*ret);
	this->_executer->executeForm(*ret);
	return (ret);
}

// * NESTED_CLASSES ********************************************************* //
OfficeBlock::MissingIntern::MissingIntern() :
	std::exception()
{
	std::cout << "[MissingIntern]() Ctor called" << std::endl;
	return ;
}
OfficeBlock::MissingIntern::~MissingIntern() throw()
{
	std::cout << "[MissingIntern]() Dtor called" << std::endl;
	return ;
}
const char *OfficeBlock::MissingIntern::what() const throw()
{
	return ("Missing intern");
}


OfficeBlock::MissingSigner::MissingSigner() :
	std::exception()
{
	std::cout << "[MissingSigner]() Ctor called" << std::endl;
	return ;
}
OfficeBlock::MissingSigner::~MissingSigner() throw()
{
	std::cout << "[MissingSigner]() Dtor called" << std::endl;
	return ;
}
const char *OfficeBlock::MissingSigner::what() const throw()
{
	return ("Missing intern");
}


OfficeBlock::MissingExecuter::MissingExecuter() :
	std::exception()
{
	std::cout << "[MissingExecuter]() Ctor called" << std::endl;
	return ;
}
OfficeBlock::MissingExecuter::~MissingExecuter() throw()
{
	std::cout << "[MissingExecuter]() Dtor called" << std::endl;
	return ;
}
const char *OfficeBlock::MissingExecuter::what() const throw()
{
	return ("Missing executer");
}
