#include "../include/Client.h"

size_t Client::validateNum(const std::string& str, char constraintL, char constraintR) const
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

const Order* Client::makeOrder(Address& currAddress, Address& finalDest, int& numPassengers) const
{
	if (order->getOrderId() != -1)
	{
		std::cout << "You cannot make an order, while you have one in action!" << std::endl;
		return;
	}
	Helper::addressInput("Enter your current address name: ", "Enter your current coordinates:\ncoordX: ", currAddress, 'c');
	Helper::addressInput("Enter the final destination: ", "Enter the final destination coordinates:\ncoordX: ", finalDest, 'c');
	numPassengers = validateNum("Enter number of passengers (The number must be between 1 and 7): ", '1', '7');
	Order* newOrder = new Order;
	newOrder->setStartAddress(currAddress);
	newOrder->setDestAddress(finalDest);
	newOrder->setPassengersNum(numPassengers);
	return newOrder;
}

void Client::check_order() const
{
	std::cout << "Your order is ";
	if (order->isAccepted())
	{
		std::cout << "accepted!" << std::endl;
	}
	else
	{
		std::cout << "not accepted yet!" << std::endl;
		return;
	}
	std::cout << "Your driver's name: " << order->getDriver()->getFirstName() << " " << order->getDriver()->getSecondName() << std::endl;
	std::cout << "The car number is: " << order->getDriver()->getCarNum() << std::endl;
	std::cout << "The driver's phone number is: " << order->getDriver()->getPhoneNum() << std::endl;
	std::cout << "The driver's rating is: " << order->getDriver()->getRating() << std::endl;
}

void Client::cancel_order()
{
	delete order;
	order = nullptr;
}

void Client::pay(double amount)
{
	if (order->isFinished())
	{
		double newBalance = getBalance() - amount;
		if (newBalance < 0)
		{
			std::cout << "You must add money to your balance first!" << std::endl;
			return;
		}
		setBalance(newBalance);
	}
	else
	{
		std::cout << "You must wait for the driver to assure the order is finished." << std::endl;
	}
}

int Client::rate() const
{
	std::string rating;
	std::cout << "Your rating must be between 1 and 5!" << std::endl;
	return validateNum("Choose your rating: ", '1', '5');
}

void Client::add_money()
{
	std::string amount;
	std::cout << "Enter the amount of money you want to add to your balance: ";
	std::getline(std::cin, amount);
	try
	{
		size_t pos;
		setBalance(getBalance() + std::stod(amount, &pos));
		if (pos < amount.length())
		{
			throw std::invalid_argument("");
		}
	}
	catch (const std::exception&)
	{
		std::cout << "The amount must contain only digits!" << std::endl;
		add_money();
	}
}