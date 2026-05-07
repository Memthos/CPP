#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    Dog original;
    original.getBrain().setIdea("I love bones!", 0);

    Dog copy = original;

    original.getBrain().setIdea("I hate cats!", 0);

	std::cout << std::endl;
    std::cout << "Original idea: " << original.getBrain().getIdea(0) << std::endl;
    std::cout << "Copy idea: " << copy.getBrain().getIdea(0) << std::endl;
	std::cout << std::endl;

    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

	std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];
}
