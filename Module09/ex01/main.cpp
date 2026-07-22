#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	try {
		std::cout << RPN::calc(argv[1]) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
