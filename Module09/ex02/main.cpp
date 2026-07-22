#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 2)
		return (1);
	try {
		PmergeMe	algo;
		algo.parser(argv);
		algo.display();
		algo.sort();
		algo.display();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
