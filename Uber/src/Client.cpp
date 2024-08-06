#include "../include/Client.h"

void Client::addressInput(const std::string& str1, const std::string& str2, Address& address) const // trqbva li da q razdelqm na oshte -> ne mislq
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
	std::cout << "Additional info (optional): " << std::endl;
	std::getline(std::cin, additionalInfo);
	address.setName(addressName);
	address.setPoint(coordinateX, coordinateY);
	address.setAdditionalInfo(additionalInfo);
}

size_t Client::validatePassengersNum() const
{
	std::string passengers;
	do
	{
		std::cout << "Enter number of passengers (The number must be between 1 and 7): ";
		std::getline(std::cin, passengers);
		if (passengers.size() >= 2)
		{
			continue;
		}
	} while (passengers[0] < '1' || passengers[0] > '7');
	return passengers[0] - '0';
}

void Client::makeOrder(Address& currAddress, Address& finalDest, int& numPassengers) const
{
	if (order.getOrderId() != -1)
	{
		std::cout << "You cannot make an order, while you have one in action!" << std::endl;
		return;
	}
	addressInput("Enter your current address: ", "Enter your current coordinates:\ncoordX: ", currAddress);
	addressInput("Enter the final destination: ", "Enter the final destination coordinates:\ncoordX: ", finalDest);
	numPassengers = validatePassengersNum();
}