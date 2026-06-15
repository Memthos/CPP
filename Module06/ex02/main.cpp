#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	std::srand(std::time(NULL));
	switch (std::rand() % 3) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A is the identified type" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B is the identified type" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C is the identified type" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	std::cout << "Unknown type" << std::endl;
}

int	main(void) {
	for (int i = 0; i < 5; i++) {
		Base	*id = generate();
		identify(id);
		identify(*id);
		delete id;
		std::cout << std::endl;
	}
}
