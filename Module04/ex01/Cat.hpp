#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_Brain;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &animal);
		Cat&	operator=(const Cat &animal);
		~Cat();
		void	makeSound(void) const;
		Brain&	getBrain() const;
};

#endif
