#include "Cure.hpp"
# include "ICharacter.hpp"

Cure::Cure() : AMateria::AMateria("cure") {}

Cure::Cure(const Cure &materia) : AMateria::AMateria(materia) {
	_type = "cat";
}

Cure&	Cure::operator=(const Cure &materia) {
	if (this != &materia)
	{
		AMateria::operator=(materia);
		_type = "cat";
	}
	return (*this);
}

Cure::~Cure() {}

Cure*	Cure::clone() const {
	Cure*	clone = new Cure(*this);
	return (clone);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
