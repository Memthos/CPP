#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor launched" << std::endl;
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain copy constructor launched" << std::endl;
	*this = brain;
}

Brain&	Brain::operator=(const Brain &brain) {
	std::cout << "Brain assignment constructor launched" << std::endl;
	if (this != &brain) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = brain._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor launched" << std::endl;
}

std::string	Brain::getIdea(const int index) const {
	if (index >= 0 && index <= 99)
		return (_ideas[index]);
	return (_ideas[0]);
}

void	Brain::setIdea(const std::string idea, const int index) {
	if (index >= 0 && index <= 99)
		_ideas[index] = idea;
}
