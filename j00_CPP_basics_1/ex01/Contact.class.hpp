// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/06 11:47:13 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/06 11:55:28 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);

	void						initInstance(void);
	static int					getNbIUsed(void);
	void						selfDecribe_Row(void);
	void						selfDecribe_Full(void);
	
private:
	static const char			*_entriesNames[11];
	static int					_nbIUsed;
	
	std::string					_entries[11];
	int							_index;
};

#endif
