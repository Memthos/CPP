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
	_vec = sortContainer(_vec);
	timerEnd = clock();
	vectorTime = (double) (timerEnd - timerStart) * 1000 / CLOCKS_PER_SEC;
	timerStart = clock();
	_deq = sortContainer(_deq);
	timerEnd = clock();
	dequeTime = (double) (timerEnd - timerStart) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vectorTime << " ms" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << dequeTime << " ms" << std::endl;
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

std::vector<size_t>	PmergeMe::jacobsthalSequence(size_t size) {
	std::vector<size_t>	seq, res;
	std::vector<bool>	used(size, false);
	size_t				hi;
	size_t				lo;

	seq.push_back(0);
	seq.push_back(1);
	while (seq.back() < size) {
		seq.push_back(seq.back() + 2 * seq[seq.size() - 2]);
	}
	if (size > 0) {
		res.push_back(0);
		used[0] = true;
	}
	for (size_t i = 2; i < seq.size(); ++i) {
		hi = std::min(seq[i], size);
		lo = seq[i - 1];
		for (size_t j = hi; j > lo; --j) {
			if (used[j - 1] == false) {
				res.push_back(j - 1);
				used[j - 1] = true;
			}
		}
	}
	for (size_t i = 0; i < size; ++i) {
		if (used[i] == false)
			res.push_back(i);
	}
	return (res);
}
