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
		C						main, pend;
		typename C::iterator	insertPos;
		bool					isOdd = 0;
		int						oddElement;
		size_t					limit = input.size();

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
				main.push_back(input[i]);
				pend.push_back(input[i + 1]);
			}
			else {
				main.push_back(input[i + 1]);
				pend.push_back(input[i]);
			}
		}
		sortContainer(main);
		for (size_t i = 0; i < pend.size(); i++) {
			insertPos = std::lower_bound(main.begin(), main.end(), pend[i]);
			main.insert(insertPos, pend[i]);
		}
		if (isOdd) {
			insertPos = std::lower_bound(main.begin(), main.end(), oddElement);
			main.insert(insertPos, oddElement);
		}
		input = main;
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
