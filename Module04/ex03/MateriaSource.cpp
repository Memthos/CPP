#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource &copy) {
	for (int i = 0; i < 4; i++) {
		if (copy._memory[i])
			_memory[i] = copy._memory[i]->clone();
		else
			_memory[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource &copy) {
	if (this != &copy) {
		for (int i = 0; i < 4; i++) {
			if (_memory[i])
				delete _memory[i];
			if (copy._memory[i])
				_memory[i] = copy._memory[i]->clone();
			else
				_memory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_memory[i])
			delete _memory[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_memory[i])
			continue ;
		else {
			_memory[i] = m;
			std::cout << "Saved " << m->getType() << " AMateria to " << i << " memory index" << std::endl;
			return ;
		}
	}
	std::cout << "Couldn't save " << m->getType() << " AMateria" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_memory[i] && _memory[i]->getType() == type)
		{
			std::cout << "Created " << _memory[i]->getType() << " AMateria" << std::endl;
			return (_memory[i]->clone());
		}
	}
	std::cout << "Didn't find AMateria of type " << type << " in MateriaSource memory" << std::endl;
	return (NULL);
}
