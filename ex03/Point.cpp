#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Fixed area(Point const a, Point const b, Point const c)
{
	float res;

	res = ((a.getX().toFloat()) * (b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));
	if (res < 0)
		res = -1 * res;
	res = 0.5f * res;
	return (Fixed(res));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areas[4];

	areas[0] = area(a, b, c);
	areas[1] = area(a, b, point);
	areas[2] = area(c, b, point);
	areas[3] = area(a, c, point);
	for (int i = 0; i < 4; i++)
	{
		if (areas[i] == 0)
			return (false);
	}
	if (areas[0] == areas[1] + areas[2] + areas[3])
		return (true);
	return (false);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
