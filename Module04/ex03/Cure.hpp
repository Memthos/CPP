#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <string>

class	Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &materia);
		Cure&	operator=(const Cure &materia);
		~Cure();
		virtual Cure*	clone() const;
		void	use(ICharacter& target);
};

#endif
