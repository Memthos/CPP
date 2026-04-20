#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{}

Point::Point(const float x, const float y): _x(x), _y(y)
{}

Point::Point(const Point &input): _x(input._x), _y(input._y)
{}

Point &Point::operator=(const Point &input)
{
	(void)input;
	return (*this);
}

Point::~Point()
{}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed	d2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed	d3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

	if (d1 > Fixed(0) && d2 > Fixed(0) && d3 > Fixed(0))
		return (true);
	else if (d1 < Fixed(0) && d2 < Fixed(0) && d3 < Fixed(0))
		return (true);
	return (false);
}
