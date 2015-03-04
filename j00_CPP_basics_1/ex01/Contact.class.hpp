

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
	static int					_nbIUsed;
	std::string					_entries[11];
	static const char			*_entriesNames[11];
	int							_index;
};

#endif
