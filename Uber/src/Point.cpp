#include "../include/Point.h"

Point::Point() : Point(0, 0) {};

int Point::getCoordX() const
{
	return x;
}

int Point::getCoordY() const
{
	return y;
}

void Point::setPointCoords(int coordX, int coordY)
{
	x = coordX;
	y = coordY;
}

double Point::getDist(const Point& other) const
{
	int dx = x - other.x;
	int dy = y - other.y;

	return sqrt(dx * dx + dy * dy);
}