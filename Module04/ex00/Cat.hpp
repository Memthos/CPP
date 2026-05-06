#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &animal);
		Cat&	operator=(const Cat &animal);
		~Cat();
		void	makeSound(void) const;
};

#endif
