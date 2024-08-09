#pragma once
#include <string>
#include "Point.h"

class Address
{
	std::string name;
	std::string additionalInfo; // da vidq dali pri suzdavane bez = "", shte go napravi kato string s duljina 0
	Point point;
public:
	Address(); //zashto pri constructora na driver se chupi, kogato = default tova.
	void setName(const std::string& name);
	void setPoint(int coodX, int coordY);
	void setAdditionalInfo(const std::string& str);

	const std::string& getName() const;
	const Point& getPoint() const;
	const std::string& getAddInfo() const;
};