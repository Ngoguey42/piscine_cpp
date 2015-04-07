// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 14:28:34 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 14:40:45 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <fstream>
#include <iostream>

static void		copy_full_file(std::ifstream &in, std::ofstream &out)
{
	char			buf[16];

	while (in.read(buf, 16))
		out.write(buf, in.gcount());
	out.write(buf, in.gcount());
	return ;
}

static void		write_and_erase(std::ofstream &out, std::string &buf2, size_t towrite)
{
	out.write(buf2.c_str(), towrite);
	buf2.erase(0, towrite);
	return ;
}

/*
** 'copy_replacing' Complicated function supporting 'new lines' and '\0' in av[2].
** Appends infile into buffers, in order to have:
**		- Min (ref_len) chars in buffer.
**		- Max (ref_len * 2 - 1) chars in buffer.
** Pushes buffers into outfile:
**		- Slow enough not to miss a 'ref_str'.
**		- Fast enough not to replace chars from 'rep_str'.
*/
static void		copy_replacing(std::ifstream &in, std::ofstream &out, int ac, char *av[])
{
	const std::string	ref_str(av[2]);
	const std::string	rep_str(ac > 3 ? av[3] : "");
	const size_t		ref_len = ref_str.length();
	const size_t		rep_len = rep_str.length();
	char				buf1[ref_len * 2 - 1];
	std::string			buf2("");
	size_t				pos;

	in.read(buf1, ref_len * 2 - 1);
	do
	{
		buf2.append(buf1, in.gcount());
		pos = buf2.find(ref_str);
		if (pos != std::string::npos)
		{
			buf2.replace(pos, ref_len, rep_str);
			write_and_erase(out, buf2, pos + rep_len);
		}
		else if (buf2.length() >= ref_len)
			write_and_erase(out, buf2, buf2.length() - ref_len + 1);
	} while (in.read(buf1, ref_len));
	out << buf2;
	return ;
}

int main(int ac, char *av[])
{
	std::ifstream	in(av[1]);
	std::string		outname;
	std::ofstream	out;

	if (ac < 2)
	{
		std::cerr << *av << ": No file to open." << std::endl;
		return 1;
	}
	if (!in)
	{
		std::cerr << *av << ": Could not open " << av[1] << "." << std::endl;
		return 1;
	}
	outname.assign(av[1]);
	outname.append(".replace");
	out.open(outname.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!out)
	{
		std::cerr << *av << ": Could not open " << outname << "." << std::endl;
		return 1;
	}
	if (ac < 3 || strlen(av[2]) == 0)
		copy_full_file(in, out);
	else
		copy_replacing(in, out, ac, av);
	return (0);
}
