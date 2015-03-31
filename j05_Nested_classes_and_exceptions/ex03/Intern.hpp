// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 12:34:23 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 13:30:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

//# include <stdexcept>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	virtual ~Intern();
	Form						*makeForm(std::string const &name,
		std::string const &target);

protected:
private:
	Intern(Intern const &src);
	Intern						&operator=(Intern const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, Intern const &rhs);

#endif // ******************************************************** INTERN_HPP //
