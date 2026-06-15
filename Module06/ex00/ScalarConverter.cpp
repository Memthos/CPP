#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &input) {
	(void)input;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &input) {
	(void)input;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool	isChar(std::string const &base)
{
	if (base.length() != 1 || !std::isdigit(base[0]))
		return (false);
	return (true);
}

static bool	isInt(std::string const &base)
{
	int	start = 0;
	if (base.empty())
		return (false);
	if (base[0] == '+' || base[0] == '-')
		start = 1;
	for (size_t i = start; i < base.length(); i++) {
		if (!std::isdigit(base[i]))
			return (false);
	}
	return (true);
}

static bool	isFloat(std::string const &base)
{
	std::string	tmp;
	char		*endptr;

	if (base.empty() || base[base.length() - 1] != 'f')
		return (false);
	if (base == "nanf" || base == "inff" || base == "+inff" || base == "-inff")
		return (true);
	tmp = base.substr(0, base.length() - 1);
	strtod(tmp.c_str(), &endptr);
	if (endptr[0] != '\0' || tmp.find('.') == std::string::npos)
		return (false);
	return (true);
}

static bool	isDouble(std::string const &base)
{
	char		*endptr;

	if (base.empty())
		return (false);
	if (base == "nan" || base == "inf" || base == "+inf" || base == "-inf")
		return (true);
	strtod(base.c_str(), &endptr);
	if (endptr[0] != '\0' || base.find('.') == std::string::npos)
		return (false);
	return (true);
}

static void	print(double nb) {
	if (nb < 0 || nb > 127 || std::isnan(nb) || std::isinf(nb))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(nb)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;

	if (nb < INT_MIN || nb > INT_MAX || std::isnan(nb) || std::isinf(nb))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nb) << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << nb << std::endl;

}

void	ScalarConverter::convert(std::string const &base) {
	if (isInt(base)) {
		long	nb = strtol(base.c_str(), NULL, 10);
		if (nb >= INT_MIN && nb <= INT_MAX) {
			print(static_cast<double>(nb));
			return ;
		}
	}
	else if (isChar(base)) {
		print(static_cast<double>(base[0]));
		return ;
	}
	else if (isFloat(base)) {
		std::string	tmp = base.substr(0, base.length() - 1);
		double	nb = strtod(tmp.c_str(), NULL);
		print(nb);
		return ;
	}
	else if (isDouble(base)) {
		double	nb = strtod(base.c_str(), NULL);
		print(nb);
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
