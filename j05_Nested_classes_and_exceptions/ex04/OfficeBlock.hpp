// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 13:52:29 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/31 15:21:36 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include <iostream>
# include <stdexcept>

class OfficeBlock
{
public:
	// * NESTED CLASSES ************* //
	class MissingIntern : public std::exception
	{
	public:
		MissingIntern();
		MissingIntern(MissingIntern const &src);
		virtual ~MissingIntern() throw();

		virtual const char *what() const throw();
	private:
		MissingIntern& operator=(MissingIntern const &rhs);
	};
	class MissingSigner : public std::exception
	{
	public:
		MissingSigner();
		MissingSigner(MissingSigner const &src);
		virtual ~MissingSigner() throw();

		virtual const char *what() const throw();
	private:
		MissingSigner& operator=(MissingSigner const &rhs);
	};
	class MissingExecuter : public std::exception
	{
	public:
		MissingExecuter();
		MissingExecuter(MissingExecuter const &src);
		virtual ~MissingExecuter() throw();

		virtual const char *what() const throw();
	private:
		MissingExecuter& operator=(MissingExecuter const &rhs);
	};

	// * CTORS / DTORS ************** //
	OfficeBlock();
	OfficeBlock(Intern const *intern, Bureaucrat const *signer,
				Bureaucrat const *executer);
	virtual ~OfficeBlock();

	// * MEMBER FUNCTIONS / METHODS * //
	void						setIntern(Intern const *intern);
	void						setSigner(Bureaucrat const *signer);
	void						setExecuter(Bureaucrat const *executer);
	Form						*doBureaucracy(std::string const &name,
		std::string const &target);
	
protected:
private:
	OfficeBlock(OfficeBlock const &src);
	OfficeBlock					&operator=(OfficeBlock const &rhs);

	Intern const				*_intern;
	Bureaucrat const			*_signer;
	Bureaucrat const			*_executer;
};
//std::ostream					&operator<<(std::ostream &o, OfficeBlock const &rhs);

#endif // *************************************************** OFFICEBLOCK_HPP //
