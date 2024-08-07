#pragma once
#include <string>
#include "Point.h"

class Address
{
	std::string name;
	Point point;
	std::string additionalInfo; // da vidq dali pri suzdavane bez = "", shte go napravi kato string s duljina 0
public:
	void setName(const std::string& name);
	void setPoint(int coodX, int coordY);
	void setAdditionalInfo(const std::string& str);
};