#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <deque>
# include <limits.h>

class	PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		template <typename C>
		void	sortContainer(C &input) {
		C			larger, smaller;
		typename C::iterator	insertPos;
		bool		isOdd = 0;
		int			oddElement;
		size_t		limit = input.size();

		if (input.size() < 2)
			return ;
		if (input.size() % 2)
		{
			--limit;
			isOdd = 1;
			oddElement = input.back();
		}
		for (size_t i = 0; i < limit; i += 2) {
			if (input[i] > input[i + 1]) {
				larger.push_back(input[i]);
				smaller.push_back(input[i + 1]);
			}
			else {
				larger.push_back(input[i + 1]);
				smaller.push_back(input[i]);
			}
		}
		sortContainer(larger);
		for (size_t i = 0; i < smaller.size(); i++) {
			insertPos = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
			larger.insert(insertPos, smaller[i]);
		}
		if (isOdd) {
			insertPos = std::lower_bound(larger.begin(), larger.end(), oddElement);
			larger.insert(insertPos, oddElement);
		}
		input = larger;
		}
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &input);
		PmergeMe&	operator=(const PmergeMe &input);
		~PmergeMe();
		void	parser(char **argv);
		void	sort();
		void	display();
		class	Error : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif
