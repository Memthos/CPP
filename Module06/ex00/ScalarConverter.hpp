#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits.h>
# include <cmath>

class	ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &input);
		ScalarConverter&	operator=(const ScalarConverter &input);
		~ScalarConverter();
	public:
		static void	convert(std::string const &base);
};

#endif
