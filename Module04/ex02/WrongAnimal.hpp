#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &animal);
		WrongAnimal&	operator=(const WrongAnimal &animal);
		virtual ~WrongAnimal();
		std::string	getType() const;
		void	makeSound() const;
	protected:
		std::string	_type;
};

#endif
