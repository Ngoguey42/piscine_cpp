#include <fstream>
#include <iostream>
#include <string.h>

static void		copy_full_file(std::ifstream &in, std::ofstream &out)
{
	char			buf[16];

	while (in.read(buf, 16))
		out.write(buf, in.gcount());
	out.write(buf, in.gcount());
	return ;
}

/*
** 'copy_replacing' Complicated function supporting new lines.
*/
static void		copy_replacing(std::ifstream &in, std::ofstream &out, int ac, char *av[])
{
		const std::string	ref_str(av[2]);
		const std::string	rep_str(ac > 3 ? av[3] : "");
		const size_t		ref_len = ref_str.length();
		const size_t		rep_len = rep_str.length();
		char				buf1[ref_len * 2 - 1];
		std::string			buf2("");
		size_t				towrite;

		in.read(buf1, ref_len * 2 - 1);
		do
		{
			buf2.append(buf1, in.gcount());
			size_t	pos = buf2.find(ref_str);
			if (pos != std::string::npos)
			{
				towrite = pos + rep_len;
				buf2.replace(pos, ref_len, rep_str);
				out.write(buf2.c_str(), towrite);
				buf2.erase(0, towrite);
			}
			else if (buf2.length() >= ref_len)
			{
				towrite = buf2.length() - ref_len + 1;
				out.write(buf2.c_str(), towrite);
				buf2.erase(0, towrite);
			}
		} while (in.read(buf1, ref_len));
		out << buf2;
	return ;
}

int main(int ac, char *av[])
{
	std::ifstream	in(av[1]);
	std::string		outname(av[1]);
	std::ofstream	out;

	if (!in || ac < 2)
	{
		std::cerr << "Could not open " << av[1] << "\n";
		return 1;
	}
	outname.append(".replace");
	out.open(outname.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!out)
	{
		std::cerr << "Could not open " << outname << "\n";
		return 1;
	}
	if (ac < 3 || strlen(av[2]) == 0)
		copy_full_file(in, out);
	else
		copy_replacing(in, out, ac, av);
	return (0);
}
