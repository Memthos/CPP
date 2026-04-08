#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed	(const Fixed& input);
		Fixed&	operator=(const Fixed& input);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
	private:
		int					_nbValue;
		static const int	_nbFracBits;
};
