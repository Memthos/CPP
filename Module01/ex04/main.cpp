#include <iostream>
#include <fstream>
#include <cstring>

int	main(int argc, char **argv)
{
	std::ifstream	input;
	std::ofstream	output;
	char			*outName;
	std::string		str;
	size_t			i;

	if (argc != 4)
		return (1);
	input.open(argv[1]);
	if (!input.is_open())
		return (1);
	outName = new char[strlen(argv[1]) + 9];
	strcpy(outName, argv[1]);
	strcat(outName, ".replace");
	output.open(outName);
	if (!output.is_open())
	{
		delete[] outName;
		input.close();
		return (1);
	}
	while (input)
	{
		std::getline(input, str);
		i = 0;
		while (str[i])
		{
			if (std::strncmp(&str[i], argv[2], strlen(argv[2])) == 0)
			{
				output << argv[3];
				i += strlen(argv[2]);
			}
			else
			{
				output << str[i];
				i++;
			}
		}
		output << std::endl;
	}
	delete[] outName;
	input.close();
	output.close();
}
