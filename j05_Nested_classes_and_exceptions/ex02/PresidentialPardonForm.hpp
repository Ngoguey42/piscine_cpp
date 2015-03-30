// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.hpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 13:18:27 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 15:02:58 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class Form;
class Bureaucrat;
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm();
	void						execute(Bureaucrat const &executor) const;
	
protected:
private:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm		&operator=(PresidentialPardonForm const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif // **************************************** PRESIDENTIALPARDONFORM_HPP //
