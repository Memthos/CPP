#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>
# include <cstdlib>
#include <iomanip>

class	BitcoinExchange;

typedef struct s_date {
	int	day;
	int	month;
	int	year;
}	t_date;

typedef void (BitcoinExchange::*parseFunc)(std::string &);

class	BitcoinExchange {
	private:
		std::map<std::string, float>	_map;
		void	parseFile(const char *filename, parseFunc func);
		void	parseLine(std::string &line);
		void	printValue(std::string &line);
		bool	isValidDate(std::string &input);
		bool	isValidAmount(const float input, const char *endptr, const float max);
	public:
		BitcoinExchange(const char *file);
		BitcoinExchange(const BitcoinExchange &input);
		BitcoinExchange&	operator=(const BitcoinExchange &input);
		~BitcoinExchange();
		class	FailedToOpen : public std::exception {
			public:
				const char* what() const throw();
		};
		class	WrongData : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif
