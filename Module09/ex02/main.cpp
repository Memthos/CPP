#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 2)
		return (1);
	try {
		PmergeMe	algo;
		algo.parser(argv);
		std::cout << "Before: " << std::endl << std::endl;
		algo.display();
		algo.sort();
		std::cout << "After: " << std::endl << std::endl;
		algo.display();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
