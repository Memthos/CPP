#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &animal);
		WrongCat&	operator=(const WrongCat &animal);
		~WrongCat();
		void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif
