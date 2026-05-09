#include "Ice.hpp"
# include "ICharacter.hpp"

Ice::Ice() : AMateria::AMateria("ice") {}

Ice::Ice(const Ice &materia) : AMateria::AMateria(materia) {}

Ice&	Ice::operator=(const Ice &materia) {
	if (this != &materia)
		AMateria::operator=(materia);
	return (*this);
}

Ice::~Ice() {}

Ice*	Ice::clone() const {
	Ice*	clone = new Ice(*this);
	return (clone);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
