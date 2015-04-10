// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 15:28:59 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 15:31:23 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &src);
	AssaultTerminator			&operator=(AssaultTerminator const &rhs);
	virtual ~AssaultTerminator();

	ISpaceMarine*				clone() const;
	void						battleCry() const;
	void						rangedAttack() const;
	void						meleeAttack() const;

	ISpaceMarine				*getNext();
	void						setNext(ISpaceMarine *next);
	
protected:
private:
	ISpaceMarine				*_next;

	static std::string const	_birthMgs;
	static std::string const	_battleCryMsg;
	static std::string const	_rangedAttackMsg;
	static std::string const	_meleeAttackMsg;
	static std::string const	_deathMgs;
};

#endif // ********************************************* ASSAULTTERMINATOR_HPP //
