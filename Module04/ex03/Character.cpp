#include "Character.hpp"

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(Character &copy) {
	*this = copy;
}

Character&	Character::operator=(Character &copy) {
	if (this != &copy) {
		_name = copy._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
			if (copy._inventory[i])
				_inventory[i] = copy._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const&	Character::getName() const {
	return (_name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			continue ;
		else {
			_inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " AMateria to " << i << " inventory index" << std::endl;
			return ;
		}
	}
	std::cout << "Couldn't equip " << m->getType() << " AMateria" << std::endl;
}

void	Character::unequip(int idx) {
	if (_inventory[idx])
	{
		std::cout << "Unequipped " << _inventory[idx]->getType() << " AMateria" << std::endl;
		_inventory[idx] = NULL;
	}
	else
		std::cout << "Inventory slot " << idx + 1 << " was already empty" << std::endl;
}

void	Character::use(int idx, ICharacter &target) {
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Inventory slot " << idx + 1 << " is empty" << std::endl;
}
