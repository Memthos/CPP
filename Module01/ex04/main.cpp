#include <iostream>
#include <fstream>
#include <cstring>

static const char	*get_outName(char *s)
{
	std::string	tmp;
	char		*name;
	tmp = s;
	tmp.append(".replace");
	name = new char[tmp.length() + 1];
	return (std::strcpy(name, tmp.c_str()));
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		str;
	size_t			idx;
	const char		*name;

	if (argc != 4 || argv[2][0] == '\0')
		return (1);
	infile.open(argv[1]);
	name = get_outName(argv[1]);
	outfile.open(name);
	if (!infile.is_open() || !outfile.is_open())
	{
		delete[] name;
		if (infile.is_open())
			infile.close();
		if (outfile.is_open())
			outfile.close();
		return (1);
	}
	while (infile)
	{
		std::getline(infile, str);
		if (std::strcmp(argv[2], argv[3]) != 0)
		{
			idx = str.find(argv[2]);
			while (idx != std::string::npos)
			{
				str.erase(idx, strlen(argv[2]));
				str.insert(idx, argv[3]);
				idx = str.find(argv[2]);

			}
		}
		outfile << str << std::endl;
	}
	delete[] name;
	infile.close();
	outfile.close();
}
