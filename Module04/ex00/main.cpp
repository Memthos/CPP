#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << animal->getType() << ": ";
    animal->makeSound();

    std::cout << dog->getType() << ": ";
    dog->makeSound();

    std::cout << cat->getType() << ": ";
    cat->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << std::endl;
	
    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->makeSound();
    delete wrongCat;

    std::cout << std::endl;
}
