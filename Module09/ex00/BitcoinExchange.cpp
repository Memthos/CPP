#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *file) {
	parseFile("data.csv", &BitcoinExchange::parseLine);
	parseFile(file, &BitcoinExchange::printValue);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &input) {
	*this = input;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &input) {
	_map = input._map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

const char*	BitcoinExchange::FailedToOpen::what() const throw() {
	return ("Failed to open file");
}

const char*	BitcoinExchange::WrongData::what() const throw() {
	return ("Wrong data in file");
}

void	BitcoinExchange::parseFile(const char *filename, parseFunc func) {
	std::ifstream	file;
	std::string		line;

	file.open(filename);
	if (!file.is_open())
		throw FailedToOpen();
	std::getline(file, line);
	while (std::getline(file, line)) {
		(this->*func)(line);
	}
}

void	BitcoinExchange::parseLine(std::string &line) {
	const char	model[] = "xxxx-xx-xx,";
	std::string	date;
	float		value;
	char		*endptr;

	for (int i = 0; i < 11; i++) {
	if (model[i] == 'x' && std::isdigit(line[i]))
		continue ;
	else if (model[i] == line[i])
		continue ;
	else
		throw WrongData();
	}
	date = line.substr(0, 10);
	value = std::strtof(line.substr(11).c_str(), &endptr);
	if (isValidDate(date) == false || isValidAmount(value, endptr, 0) == false)
		throw WrongData();
	_map.insert(std::pair<std::string, float>(date, value));
}

void	BitcoinExchange::printValue(std::string &line) {
	const char								model[] = "xxxx-xx-xx | ";
	std::string								date_part;
	std::string								value_part;
	float									input_value;
	char									*endptr;
	std::map<std::string, float>::iterator	it;

	for (int i = 0; i < 13; i++) {
		if (model[i] == 'x' && std::isdigit(line[i]))
			continue ;
		else if (model[i] == line[i])
			continue ;
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			return ;
		}
	}
	date_part = line.substr(0, 10);
	if (isValidDate(date_part) == false)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	value_part = line.substr(13);
	input_value = std::strtof(value_part.c_str(), &endptr);
	if (isValidAmount(input_value, endptr, 1000) == false)
	{
		std::cerr << "Error: invalid number" << std::endl;
		return ;
	}
	it = _map.lower_bound(date_part);
	if (it == _map.begin() && it->first != date_part)
	{
		std::cout << "Date is too early" << std::endl;
		return ;
	}
	else if (it->first != date_part)
		--it;
	std::cout << date_part << " =>" << value_part << " = " << it->second * input_value << std::endl;
}

bool	BitcoinExchange::isValidDate(std::string &input) {
	t_date	date;
	int		maxDay;

	date.day = std::atoi(input.c_str());
	date.month = std::atoi(input.c_str() + 5);
	date.year = std::atoi(input.c_str() + 8);
	if (date.day < 1 || date.month < 1 || date.month > 12 || date.year < 0)
		return (false);
	switch (date.month)
	{
		case 2:
		{
			maxDay = 28;
			if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0))
				maxDay = 29;
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			maxDay = 30;
			break ;
		}
		default:
			maxDay = 31;
	}
	if (maxDay > date.day)
		return (false);
	return (true);
}

bool	BitcoinExchange::isValidAmount(const float input, const char *endptr, const float max) {
	if (endptr != NULL && *endptr != '\0')
		return (false);
	else if (input < 0 || (max != 0 && input > max))
		return (false);
	return (true);
}
