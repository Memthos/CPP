#ifndef __FIXED_H__
# define __FIXED_H__

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
		bool	operator>(const Fixed& comp) const;
		bool	operator<(const Fixed& comp) const;
		bool	operator>=(const Fixed& comp) const;
		bool	operator<=(const Fixed& comp) const;
		bool	operator==(const Fixed& comp) const;
		bool	operator!=(const Fixed& comp) const;
		Fixed	operator+(const Fixed& add) const;
		Fixed	operator-(const Fixed& sub) const;
		Fixed	operator*(const Fixed& mul) const;
		Fixed	operator/(const Fixed& div) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
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
