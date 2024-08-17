#include "../include/Helper.h"
#include <regex>

void Helper::validateCoordinate(const std::string& coord, double& coordinateNum, std::string& coordinateString)
{
	std::regex coordinatePattern("^[+-]?[0-9]+$");
	std::cout << coord;
	std::getline(std::cin, coordinateString);
	while (!std::regex_match(coordinateString, coordinatePattern))
	{
		std::cout << "coordX: ";
		std::getline(std::cin, coordinateString);
	}
	coordinateNum = std::stod(coordinateString);
}

void Helper::addressInput(const std::string& str1, const std::string& str2, Address& address, char ch) // trqbva li da q razdelqm na oshte -> ne mislq
{
	std::string addressName, additionalInfo, coordinateXStr, coordinateYStr;
	double coordinateX = 0, coordinateY = 0;
	
	std::cout << str1;
	std::getline(std::cin, addressName);
	while (addressName.size() == 0)
	{
		std::cout << "The destination name must be at least 1 character!" << std::endl;
		std::cout << str1;
		std::getline(std::cin, addressName);
	}

	std::cout << str2 << std::endl;
	validateCoordinate("coordX: ", coordinateX, coordinateXStr);
	validateCoordinate("coordY: ", coordinateY, coordinateYStr);

	if (ch != 'd')
	{
		std::cout << "Additional info (optional): " << std::endl;
		std::getline(std::cin, additionalInfo);
		address.setAdditionalInfo(additionalInfo);
	}
	address.setName(addressName);
	address.setPoint(coordinateX, coordinateY);
}

bool Helper::isOnlyDigits(const std::string& str)
{
	if (str[0] == '-')
	{
		std::cout << "The number must be positive!" << std::endl;
		return false;
	}
	size_t strLen = str.length();
	if (strLen == 0)
	{
		std::cout << "You must enter a value!" << std::endl;
		return false;
	}
	for (size_t i = 0; i < strLen; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			std::cout << "Must contain only digits!" << std::endl;
			return false;
		}
	}
	return true;
}

size_t Helper::validateNum(const std::string& str, char constraintL, char constraintR)
{
	std::string passengers;
	while (true)
	{
		std::cout << str;
		std::getline(std::cin, passengers);
		if (passengers.size() >= 2)
		{
			continue;
		}
		if (passengers[0] < constraintL || passengers[0] > constraintR)
		{
			continue;
		}
		break;
	}
	return passengers[0] - '0';
}