#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& input);
		Fixed&	operator=(const Fixed& input);
		~Fixed();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		private:
		int					_nbValue;
		static const int	_nbFracBits;
	};

std::ostream&	operator<<(std::ostream &stream, const Fixed &value);

#endif
