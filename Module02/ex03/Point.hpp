#ifndef __POINT_H__
# define __POINT_H__

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point	(const float x, const float y);
		Point	(const Point& input);
		Point&	operator=(const Point& input);
		~Point();
		Fixed	getX() const;
		Fixed	getY() const;
	private:
		const Fixed	_x;
		const Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
