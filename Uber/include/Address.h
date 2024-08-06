#pragma once
#include <string>
#include "Point.h"

class Address
{
	std::string name;
	Point point;
	std::string additionalInfo;
public:
	void setName(const std::string& name);
	void setPoint(int coodX, int coordY);
	void setAdditionalInfo(const std::string& str);
};