// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/06 11:47:16 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/06 12:04:08 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <Contact.class.hpp>
#include <iostream>
#include <string>

Contact::Contact(void) {return ;}
Contact::~Contact(void) {return ;}

int					Contact::_nbIUsed = 0;
int					Contact::getNbIUsed(void) {return (Contact::_nbIUsed); }
const char			*Contact::_entriesNames[11] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Login",
	"Postal Address",
	"Email Address",
	"Phone Number",
	"Birthday Date",
	"Favorite Meal",
	"Underwear Color",
	"Darkest Secret"
};

static std::string	Cell(std::string String)
{
	const size_t	len = String.length();

	if (len <= 10)
		return (String.insert(0, 10 - len, ' '));
	return (String.replace(9, len - 9, "."));
}

void				Contact::initInstance(void)
{
	this->_index = Contact::_nbIUsed++;
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Please input your " << Contact::_entriesNames[i] << ": ";
		std::getline(std::cin, this->_entries[i]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
	}
	std::cout << "Contact created." << std::endl;
	return ;
}


void				Contact::selfDecribe_Row(void)
{
	std::cout << "*         " << this->_index <<
		'|' << Cell(this->_entries[0]) <<
		'|' << Cell(this->_entries[1]) <<
		'|' << Cell(this->_entries[2]) <<
		'*' << std::endl;
	return ;
}
void				Contact::selfDecribe_Full(void)
{
	for (int i = 0; i < 11; i++)
		std::cout <<  Contact::_entriesNames[i] << ": '" << this->_entries[i] <<
			'\'' << std::endl;
	return ;
}
