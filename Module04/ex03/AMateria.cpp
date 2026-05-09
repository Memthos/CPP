#include "AMateria.hpp"
# include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &materia) {
	*this = materia;
}

AMateria&	AMateria::operator=(const AMateria &materia) {
	if (this != &materia)
		_type = materia._type;
	return (*this);
}

AMateria::~AMateria() {}

std::string const&	AMateria::getType() const {
	return (_type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* uses " << _type << " AMateria on " << target.getName() <<" *" << std::endl;
}
