// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 15:22:34 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 15:24:11 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class Form;
class Bureaucrat;
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm();
	void						execute(Bureaucrat const &executor) const;
	
protected:
private:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm		&operator=(ShrubberyCreationForm const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif // ***************************************** SHRUBBERYCREATIONFORM_HPP //
