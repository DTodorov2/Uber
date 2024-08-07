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

void Driver::accept_order(int orderId, int minutes) // shtom go priemam kato argument, predpolagam, che sistemata shte si ima orderId-to veche\
i nqma da ima smisul da go vrushtam ot taq funkciq
{
	if (orderId < 1 || orderId > orders.size())
	{
		throw std::invalid_argument("Invalid orderId!");
	}
	orders[orderId - 1]->setAccepted(true);
	orders[orderId - 1]->setDriver(this);
	orders[orderId - 1]->setMinutes(minutes);
	busy = true;
} // realno sled kato accept-ne, bi trqbvalo vsichki drugi poruchki da sa izprateni kum drugi driver-i i v orders da ima samo 1 element.

void Driver::decline_order(int orderId) // da vidq v tetradkata kvo sum pisal
{
	if (orderId < 1 || orderId > orders.size())
	{
		throw std::invalid_argument("Invalid orderId!");
	}
	if (orders[orderId - 1]->getDriver() == this)
	{
		orders[orderId - 1]->setAccepted(false);
		orders[orderId - 1]->setDriver(nullptr); //tova go pravq, za da moje, ako iskame da otkajem nqkakva poruchka, koqto predi tova sme prieli\
			da q ostavim v purvonachalno sustoqnie
		orders[orderId - 1]->setMinutes(0);
		busy = false;
	}
	orders[orderId - 1] = orders[orders.size() - 1];
	orders.pop_back();
}

void Driver::finish_order(int orderId)
{
	if (orderId < 1 || orderId > orders.size())
	{
		throw std::invalid_argument("Invalid orderId!");
	}
	busy = false;
	setAddress(orders[orderId - 1]->getDestAddress());
	orders.pop_back(); //sled tozi red, bi trqbvalo v orders da nqma nishto i da e sus size 0
	//pri pay se iztriva samata poruchka, sled kato se plati, shtoto vinagi sled finish_order trqbva da se plati i taka nqma da ostane visqshta pamet
}