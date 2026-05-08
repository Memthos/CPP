#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		Brain&	operator=(const Brain &brain);
		~Brain();
		std::string	getIdea(const int index) const;
		void	setIdea(const std::string idea, const int index);
};

#endif
