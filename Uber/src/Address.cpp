#include "../include/Address.h"

void Address::setName(const std::string& name)
{
	this->name = name;
}

void Address::setPoint(int coordX, int coordY)
{
	point.setPointCoords(coordX, coordY);
}

void Address::setAdditionalInfo(const std::string& str)
{
	additionalInfo = str;
}

const std::string& Address::getName() const
{
	return name;
}

const Point& Address::getPoint() const
{
	return point;
}

const std::string& Address::getAddInfo() const
{
	return additionalInfo;
}

std::ostream& operator<<(std::ostream& os, const Address& add)
{
	os << "Your current address is: " << std::endl;
	os << "Address name: " << add.name << std::endl;
	os << "Coord x: " << add.point.getCoordX() << " Coord y: " << add.point.getCoordY() << std::endl;
	return os;
}