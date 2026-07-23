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
		std::vector<size_t>	jacobsthalSequence(size_t size);
		template <typename C>
		C	sortContainer(C input) {
			C						main, pend, sorted;
			std::vector<size_t>		seq;
			typename C::iterator	insertPos, bound;
			bool					isOdd = 0;
			int						oddElement;
			size_t					idx, limit = input.size();

			if (input.size() < 2)
				return (input);
			if (input.size() % 2)
			{
				--limit;
				isOdd = 1;
				oddElement = input.back();
				input.pop_back();
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
			sorted = sortContainer(main);
			seq = jacobsthalSequence(pend.size());
			for (size_t j = 0; j < seq.size(); j++) {
				idx = seq[j];
				bound = std::lower_bound(sorted.begin(), sorted.end(), main[idx]);
				insertPos = std::lower_bound(sorted.begin(), bound, pend[idx]);
				sorted.insert(insertPos, pend[idx]);
			}
			if (isOdd) {
				insertPos = std::lower_bound(sorted.begin(), sorted.end(), oddElement);
				sorted.insert(insertPos, oddElement);
			}
			return (sorted);
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
