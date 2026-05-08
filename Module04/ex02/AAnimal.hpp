#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &animal);
		AAnimal&	operator=(const AAnimal &animal);
		virtual ~AAnimal();
		std::string	getType() const;
		virtual void	makeSound() const = 0;
	protected:
		std::string	_type;
};

#endif
