#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Point.h"

class Address
{
	std::string name;
	std::string additionalInfo;
	Point point;
public:
	Address() = default; //zashto pri constructora na driver se chupi, kogato = default tova.
	void setName(const std::string& name);
	void setPoint(int coodX, int coordY);
	void setAdditionalInfo(const std::string& str);
	void writeAddressIntoFile(std::ofstream& ofs) const;

	const std::string& getName() const;
	const Point& getPoint() const;
	const std::string& getAddInfo() const;

	friend std::ostream& operator<<(std::ostream& os, const Address& add);
};