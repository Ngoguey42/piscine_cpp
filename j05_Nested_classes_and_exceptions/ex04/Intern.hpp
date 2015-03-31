// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 12:34:23 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 15:06:23 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

# include <stdexcept>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	// * NESTED CLASSES ************* //
	class UnknownForm : public std::exception
	{
	public:
		UnknownForm();
		virtual ~UnknownForm() throw();
		UnknownForm(UnknownForm const &src);

		virtual const char *what() const throw();
	private:
		UnknownForm& operator=(UnknownForm const &rhs);
	};
	
	// * CTORS / DTORS ************** //
	Intern();
	virtual ~Intern();
	
	// * MEMBER FUNCTIONS / METHODS * //
	Form						*makeForm(std::string const &name,
							std::string const &target) const;
	
protected:
private:
	Intern(Intern const &src);
	Intern						&operator=(Intern const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, Intern const &rhs);

#endif // ******************************************************** INTERN_HPP //
