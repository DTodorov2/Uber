#pragma once
#include <cmath>

class Point
{
	int x;
	int y;
public:
	Point(int x, int y) : x(x), y(y) {};
	Point();
	double getDist(const Point& other) const;
	int getCoordX() const;
	int getCoordY() const;

	void setPointCoords(int coordX, int coordY);
};