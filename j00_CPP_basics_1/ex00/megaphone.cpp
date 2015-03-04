
#include <iostream>

static char	format_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

static void	format_string(char *str)
{
	const char	*head = str;
	const char	*orig = str;

	while (*head == ' ')
		head++;
	while (*head != '\0')
		*str++ = format_char(*head++);
	do
	{
		*str-- = '\0';
	} while(str >= orig && *str == ' ');
	return ;
}

int			main(int ac, char *av[])
{
	int		t = 0;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (av++; --ac; av++)
	{
		format_string(*av);
		if (**av == '\0')
			continue ;
		else if (t)
			std::cout << ' ';
		else
			t = 1;
		std::cout << *av;
	}
	std::cout << std::endl;
	return (0);
}
