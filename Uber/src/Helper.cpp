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