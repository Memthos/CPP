#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &input) {
	(void)input;
}
PmergeMe& PmergeMe::operator=(const PmergeMe &input) {
	(void)input;
	return (*this);
}

PmergeMe::~PmergeMe() {}

const char*	PmergeMe::Error::what() const throw() {
	return ("Error");
}

void	PmergeMe::parser(char **argv) {
	char	*endptr;
	long	res;

	for (int i = 1; argv[i]; i++) {
		res = std::strtol(argv[i], &endptr, 10);
		if ((endptr && *endptr != '\0'))
			throw Error();
		else if (res < 1 || res > INT_MAX)
			throw Error();
		_vec.push_back(static_cast<int>(res));
		_deq.push_back(static_cast<int>(res));
	}
}

void	PmergeMe::sort() {
	clock_t	timerStart;
	clock_t	timerEnd;
	double	vectorTime;
	double	dequeTime;
	timerStart = clock();
	sortContainer(_vec);
	timerEnd = clock();
	vectorTime = (double) (timerEnd - timerStart) / CLOCKS_PER_SEC * 1000000;
	timerStart = clock();
	sortContainer(_deq);
	timerEnd = clock();
	dequeTime = (double) (timerEnd - timerStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
	std::cout << std::endl;
}

void	PmergeMe::display() {
	std::cout << "Vector: " << std::endl;
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i];
		if (i < _vec.size() - 1)
			std::cout << " ";
		else
			std::cout << std::endl << std::endl;
	}
	std::cout << "Deque: " << std::endl;
	for (size_t i = 0; i < _deq.size(); i++) {
		std::cout << _deq[i];
		if (i < _deq.size() - 1)
			std::cout << " ";
		else
			std::cout << std::endl << std::endl;
	}
}
