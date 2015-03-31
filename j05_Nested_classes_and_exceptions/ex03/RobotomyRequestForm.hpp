// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.hpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 15:07:43 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 15:08:43 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class Form;
class Bureaucrat;
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm();
	void						execute(Bureaucrat const &executor) const;
	
protected:
private:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm		&operator=(RobotomyRequestForm const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif // ******************************************* ROBOTOMYREQUESTFORM_HPP //
