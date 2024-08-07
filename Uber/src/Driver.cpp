#include "../include/Driver.h"

void Driver::changeAddress()
{
	Helper::addressInput("Enter the new destination name: ", "Enter the new coordinates : \ncoordX: ", this->address);
}

void Driver::check_messages() const
{
	size_t orderVecLen = orders.size();
	for (size_t i = 0; i < orderVecLen; i++)
	{
		std::cout << "Order number: " << i + 1 << std::endl;
		std::cout << orders[i]->getNameOrderPerson() << "has made an order from: " << std::endl;
		std::cout << orders[i]->getStartAddress().getName() << " " 
				<< orders[i]->getStartAddress().getPoint().x << " " 
				<< orders[i]->getStartAddress().getPoint().y << " " 
				<< orders[i]->getStartAddress().getAddInfo() << std::endl;
		std::cout << "To: " << std::endl;
		std::cout << orders[i]->getDestAddress().getName() << " "
			<< orders[i]->getDestAddress().getPoint().x << " "
			<< orders[i]->getDestAddress().getPoint().y << " "
			<< orders[i]->getDestAddress().getAddInfo() << std::endl;
	}
}