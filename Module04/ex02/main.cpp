#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    AAnimal a; //Error

    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

	std::cout << std::endl;
    cat->makeSound();
    dog->makeSound();
	std::cout << std::endl;

    delete dog;
    delete cat;

    return 0;
}
