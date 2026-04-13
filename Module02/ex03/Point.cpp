#include "Point.hpp"

Point::Point()
{
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::Point(const float x, const float y)
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::Point(const Point &input)
{
	*this = input;
}

Point &Point::operator=(const Point &input)
{
	if (this != &input)
	{
		this->_x = input._x;
		this->_y = input._y;
	}
	return (*this);
}

Point::~Point()
{
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	return false;
}
