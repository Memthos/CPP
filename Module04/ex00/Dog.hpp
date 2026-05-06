#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &animal);
		Dog&	operator=(const Dog &animal);
		~Dog();
		void	makeSound(void) const;
};

#endif
