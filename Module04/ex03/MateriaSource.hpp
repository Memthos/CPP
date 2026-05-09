#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource : public IMateriaSource {
	private:
		AMateria*	_memory[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource &copy);
		MateriaSource&	operator=(MateriaSource &copy);
		~MateriaSource();
		void	learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const &type);
};

#endif
