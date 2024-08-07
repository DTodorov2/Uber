#pragma once
#include <string>
#include "Point.h"

class Address
{
	std::string name;
	std::string additionalInfo; // da vidq dali pri suzdavane bez = "", shte go napravi kato string s duljina 0
	struct Point {
		int x;
		int y;
		Point(int x, int y) : x(x), y(y) {};
		double getDist(const Point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;
			
			return sqrt(dx * dx + dy * dy);
		}
	};
	Point point;
public:
	void setName(const std::string& name);
	void setPoint(int coodX, int coordY);
	void setAdditionalInfo(const std::string& str);

	const std::string getName() const;
	const Point& getPoint() const;
	const std::string& getAddInfo() const;
};