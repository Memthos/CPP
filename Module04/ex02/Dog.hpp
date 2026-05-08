#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_Brain;
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &animal);
		Dog&	operator=(const Dog &animal);
		~Dog();
		void	makeSound(void) const;
		Brain&	getBrain() const;
};

#endif
