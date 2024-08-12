#include "../include/Helper.h"

void Helper::addressInput(const std::string& str1, const std::string& str2, Address& address, char ch) // trqbva li da q razdelqm na oshte -> ne mislq
{
	std::string addressName, additionalInfo;
	int coordinateX = 0, coordinateY = 0;
	std::cout << str1;
	std::getline(std::cin, addressName);
	std::cout << str2;
	std::cin >> coordinateX;
	std::cin.ignore();
	std::cout << "coordY: ";
	std::cin >> coordinateY;
	std::cin.ignore();
	if (ch == 'd')
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
		else if (str[i] == '0' && strLen == 1)
		{
			std::cout << "The number must be grater than 0!" << std::endl;
			return false;
		}
	}
	return true;
}

size_t Helper::validateNum(const std::string& str, char constraintL, char constraintR)
{
	std::string passengers;
	do
	{
		std::cout << str;
		std::getline(std::cin, passengers);
		if (passengers.size() >= 2)
		{
			continue;
		}
	} while (passengers[0] < constraintL || passengers[0] > constraintR);
	return passengers[0] - '0';
}