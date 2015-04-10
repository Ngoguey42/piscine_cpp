// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:43:57 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 15:25:54 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &src);
	TacticalMarine				&operator=(TacticalMarine const &rhs);
	virtual ~TacticalMarine();

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

#endif // ************************************************ TACTICALMARINE_HPP //
