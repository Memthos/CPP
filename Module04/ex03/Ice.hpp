#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <string>

class	Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &materia);
		Ice&	operator=(const Ice &materia);
		~Ice();
		virtual Ice*	clone() const;
		void	use(ICharacter& target);
};

#endif
